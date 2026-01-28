/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_threads_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:18:23 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/28 16:28:58 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	f_init_threads(t_philo **ph, pthread_t *threads)
{
	int	i;

	i = 0;
	ph[0]->input->start_time = f_get_time();
	while (ph[i])
	{
		ph[i]->lte = ph[0]->input->start_time;
		i++;
	}
	i = 0;
	while (ph[i])
	{
		if (pthread_create(&threads[i], NULL, f_philo_routine, ph[i]) != 0)
		{
			pthread_mutex_lock(ph[0]->input->live);
			ph[0]->input->life = false;
			pthread_mutex_unlock(ph[0]->input->live);
			while (--i >= 0)
				pthread_join(threads[i], NULL);
			return (-1);
		}
		i++;
	}
	if (pthread_create(&threads[i], NULL, f_ghost_routine, ph) != 0)
	{
		pthread_mutex_lock(ph[0]->input->live);
		ph[0]->input->life = false;
		pthread_mutex_unlock(ph[0]->input->live);
		while (--i >= 0)
			pthread_join(threads[i], NULL);
		return (-1);
	}
	return (0);
}

void f_join_threads(t_in in, pthread_t *threads)
{
	int i = 0;
	while (i < in.nop + 1)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return ;
}


/*

 hier kommt die initialisierung pthread_create()
 -> return value checken und wenn fehlschlägt bis i joinen,
 -1 returnen alles davor in main freen etc.




*/

// ... nach f_init_philos ...
