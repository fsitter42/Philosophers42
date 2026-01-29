/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ghost_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:19:15 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/29 12:29:05 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		f_check_death(t_philo *ph);
void	f_print_death(t_philo *p, char *status);
int		f_check_full(t_philo **ph);

void	*f_ghost_routine(void *p)
{
	t_philo	**philos;
	int		i;
	int		nop;

	philos = (t_philo **)p;
	nop = philos[0]->input->nop;
	usleep(600);
	while (1)
	{
		i = 0;
		while (i < nop)
		{
			if (f_check_death(philos[i]) == 1)
				return (NULL);
			i++;
		}
		if (f_check_full(philos) == 1)
			return (NULL);
		usleep(600);
	}
	return (NULL);
}

int	f_check_death(t_philo *ph)
{
	pthread_mutex_lock(ph->sensor);
	if (f_get_time() - ph->lte > ph->input->ttd)
	{
		ph->input->life = false;
		pthread_mutex_unlock(ph->sensor);
		f_print_death(ph, "died");
		return (1);
	}
	pthread_mutex_unlock(ph->sensor);
	return (0);
}

void	f_print_death(t_philo *p, char *status)
{
	uint64_t	timestamp;

	pthread_mutex_lock(p->input->log);
	timestamp = f_get_time() - p->input->start_time;
	printf("%lu %lu %s.\n", timestamp, p->index, status);
	pthread_mutex_unlock(p->input->log);
}

int	f_check_full(t_philo **ph)
{
	size_t	i;
	size_t	full;
	t_in	*in;

	i = 0;
	full = 0;
	in = ph[0]->input;
	if (in->notepme == -1)
		return (0);
	while (i < in->nop)
	{
		pthread_mutex_lock(ph[i]->sensor);
		if (ph[i]->ate_x_times >= in->notepme)
			full++;
		pthread_mutex_unlock(ph[i]->sensor);
		i++;
	}
	if (full == in->nop)
	{
		pthread_mutex_lock(in->live);
		in->life = false;
		pthread_mutex_unlock(in->live);
		return (1);
	}
	return (0);
}
