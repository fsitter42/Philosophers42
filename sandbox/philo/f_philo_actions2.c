/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_forks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:18:11 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/28 13:41:16 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_take_fork(t_philo *philo, pthread_mutex_t *fork);
void	f_leave_fork(pthread_mutex_t *fork);

void	f_take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	f_print_status(philo, "has taken a fork");
}

void	f_leave_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}

void	f_take_forks(t_philo *ph, pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	f_take_fork(ph, f1);
	f_take_fork(ph, f2);
}

void	f_leave_forks(pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	f_leave_fork(f2);
	f_leave_fork(f1);
}
