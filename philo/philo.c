/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:11:09 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/27 13:21:26 by fsitter          ###   ########.fr       */
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
		return (printf("ERROR: init_table\n"), 1);
	philo = f_init_philos(&input, table.forks);
	if (!philo)
	{
		printf("ERROR: f_init_philos\n");
		f_destroy_table(&table, &input);
		return (1);
	}

	// im here::::::
	// create threads
	// joind threads
	f_sleep(400);
	printf("%lu %lu is eating.\n", f_get_time() - philo[0]->input->start_time, philo[0]->index);

	
	philo = f_free_philos(philo);
	f_destroy_table(&table, &input);
}

/*
ACHTUNG: ab Zeile 32 bei einem Fehler im Rückgabewert philo = f_free_philo() und f_destroy_table() aufrufen!!!!

next:
	- create the threads
	- join them back

	- create routine for philos
	- create routine for live and log ??


1 a.out
2 number_of_philosophers
3 time_to_die
4 time_to_eat
5 time_to_sleep
6 [number_of_times_each_philosopher_must_eat]


am schluss alles auf NULL etc setzten
*/