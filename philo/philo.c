/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:11:09 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/24 11:13:40 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_in	input;

	if (f_manage_input(ac, av, &input) < 0)
		return (printf("ERROR: Input\n"), 1);
	input.start_time = f_get_time();
}

/*

make a valid input function that tests
 - ac!=5 or 6,
 - checks for negativ
 - checks if overflow or negative number,
 - if not -> converts the positive number in s to long


check for strlen of itoa to compare for valid input?
f_valid_ulong > return 0 on error weil 0 auch beendet wird


1 a.out
2 number_of_philosophers
3 time_to_die
4 time_to_eat
5 time_to_sleep
6 [number_of_times_each_philosopher_must_eat]
*/