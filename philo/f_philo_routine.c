/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_philo_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:22:24 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/30 13:03:32 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*f_one_philo(t_philo *philo);
int		f_is_full(t_philo *philo);

void	*f_philo_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->input->nop == 1)
		return (f_one_philo(philo));
	if (philo->index % 2 == 0)
		f_sleep(philo->input->tte / 2);
	while (f_is_live(philo))
	{
		if (!f_is_full(philo))
			f_philo_eat(philo);
		if (!f_is_live(philo) || f_is_full(philo))
			break ;
		f_philo_sleep(philo);
		f_philo_think(philo);
	}
	return (NULL);
}

void	*f_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	f_print_status(philo, "has taken a fork");
	f_sleep(philo->input->ttd);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

int	f_is_live(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(philo->input->live);
	ret = philo->input->life;
	pthread_mutex_unlock(philo->input->live);
	return (ret);
}

int	f_is_full(t_philo *philo)
{
	int	ret;

	ret = 0;
	if (philo->input->notepme < 0)
		return (ret);
	pthread_mutex_lock(philo->sensor);
	if (philo->input->notepme <= (int)philo->ate_x_times)
		ret = 1;
	pthread_mutex_unlock(philo->sensor);
	return (ret);
}
