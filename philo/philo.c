/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:11:09 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/24 14:19:28 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_in	input;
	t_table	table;
	t_philo	**philo;

	if (f_manage_input(ac, av, &input) < 0)
		return (printf("ERROR: Input\n"), 1);
	
	if (f_init_table(&table, &input) < 0)
		return(printf("ERROR: Malloc\n"), 1);
	
}

/*
next:
	- f_init_table
	- free input ?? nothing allocated
	- free table


1 a.out
2 number_of_philosophers
3 time_to_die
4 time_to_eat
5 time_to_sleep
6 [number_of_times_each_philosopher_must_eat]
*/