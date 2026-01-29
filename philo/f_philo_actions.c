/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_philo_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:09:37 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/29 12:25:31 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_philo_eat(t_philo *ph)
{
	pthread_mutex_t	*f1;
	pthread_mutex_t	*f2;

	f1 = ph->left_fork;
	f2 = ph->right_fork;
	if (ph->index % 2 == 0)
	{
		f1 = ph->right_fork;
		f2 = ph->left_fork;
	}
	f_take_forks(ph, f1, f2);
	f_print_status(ph, "is eating");
	pthread_mutex_lock(ph->sensor);
	ph->lte = f_get_time();
	ph->ate_x_times += 1;
	pthread_mutex_unlock(ph->sensor);
	f_sleep(ph->input->tte);
	f_leave_forks(f1, f2);
}

void	f_philo_sleep(t_philo *ph)
{
	f_print_status(ph, "is sleeping.");
	f_sleep(ph->input->tts);
}

void	f_philo_think(t_philo *ph)
{
	f_print_status(ph, "is thinking.");
	if (ph->input->nop % 2 != 0)
		f_sleep(1);
}

void	f_print_status(t_philo *p, char *status)
{
	uint64_t	timestamp;

	if (!f_is_live(p))
		return ;
	pthread_mutex_lock(p->input->log);
	timestamp = f_get_time() - p->input->start_time;
	printf("%lu %lu %s.\n", timestamp, p->index, status);
	pthread_mutex_unlock(p->input->log);
}
