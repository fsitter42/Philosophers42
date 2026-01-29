/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_threads_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:18:23 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/29 12:11:02 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_kill(t_philo **philo);
void	f_set_time(t_philo **philo);

int	f_init_threads(t_philo **ph, pthread_t *threads)
{
	int	i;

	i = 0;
	f_set_time(ph);
	while (ph[i])
	{
		if (pthread_create(&threads[i], NULL, f_philo_routine, ph[i]) != 0)
		{
			f_kill(ph);
			while (--i >= 0)
				pthread_join(threads[i], NULL);
			return (-1);
		}
		i++;
	}
	if (pthread_create(&threads[i], NULL, f_ghost_routine, ph) != 0)
	{
		f_kill(ph);
		while (--i >= 0)
			pthread_join(threads[i], NULL);
		return (-1);
	}
	return (0);
}

void	f_join_threads(t_in in, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < in.nop + 1)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return ;
}

void	f_kill(t_philo **philo)
{
	pthread_mutex_lock(philo[0]->input->live);
	philo[0]->input->life = false;
	pthread_mutex_unlock(philo[0]->input->live);
}

void	f_set_time(t_philo **philo)
{
	int	i;

	i = 0;
	philo[0]->input->start_time = f_get_time();
	while (philo[i])
	{
		philo[i]->lte = philo[0]->input->start_time;
		i++;
	}
}

/*

 hier kommt die initialisierung pthread_create()
 -> return value checken und wenn fehlschlägt bis i joinen,
 -1 returnen alles davor in main freen etc.




*/

// ... nach f_init_philos ...
