/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:11:09 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/15 16:18:09 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int main(int ac, char **av)
int main(void)
{
	// if (ac != 5 || ac != 6)
	// 	return (-1);
	char *longmax = "  \t 9223372036854775807";
	
	if(f_find_overflow_negative(longmax) == 1)
		printf("good\n");
	else
		printf("overflow or negative\n");
	
	
}

/*

make a valid input function that tests
 - ac!=5 or 6,
 - checks for negativ
 - checks if overflow or negative number,
 - if not -> converts the positive number in s to long
	
1 a.out
2 number_of_philosophers
3 time_to_die
4 time_to_eat
5 time_to_sleep
6 [number_of_times_each_philosopher_must_eat]
*/