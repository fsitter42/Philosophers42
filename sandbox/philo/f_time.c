/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_time.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:34:44 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/30 01:22:09 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	f_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	f_sleep(uint64_t ms)
{
	uint64_t	start;

	start = f_get_time();
	while ((f_get_time() - start) < ms)
		usleep(600);
}

/*
Checke forks.c NOTES:
*/