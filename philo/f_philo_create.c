/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_philo_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:51:40 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/25 15:25:03 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_fill_philos(t_philo *ph, int i, t_in *in, pthread_mutex_t *forks);

t_philo	**f_init_philos(t_in *input, pthread_mutex_t *forks)
{
	int		i;
	t_philo	**philos;

	i = 0;
	philos = malloc(sizeof(t_philo *) * (input->nop + 1));
	if (!philos)
		return (NULL);
	while (i < input->nop)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			while (--i >= 0)
				free(philos[i]);
			free(philos);
			philos = NULL;
			return (philos);
		}
		f_fill_philos(philos[i], i, input, forks);
		i++;
	}
	philos[i] = NULL;
	return (philos);
}

void	f_fill_philos(t_philo *ph, int i, t_in *in, pthread_mutex_t *forks)
{
	ph->index = i + 1;
	ph->ate_x_times = 0;
	ph->alive = 1;
	ph->lte = in->start_time;
	ph->input = in;
	if (i == 0)
		ph->left_fork = &forks[in->nop - 1];
	else
		ph->left_fork = &forks[i - 1];
	ph->right_fork = &forks[i];
	return ;
}

t_philo	**f_free_philos(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i] != NULL)
	{
		free(philos[i]);
		i++;
	}
	free(philos);
	philos = NULL;
	return (philos);
}
// ich bin hier
/*
jetzt:
f_init philos genau so protecten wie init forks also bei fehler
während anlegen while(--i >= 0) -> pthread_join()
um bereits erstellte/laufende threads wieder einzugliedern
dann:
f_join_philos -> um sie am schluss aufzuräumen
*/