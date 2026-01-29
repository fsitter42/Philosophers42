/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:11:09 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/29 12:59:20 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int f_input_and_table(int ac, char **av, t_in *input, t_table *table);

int	main(int ac, char **av)
{
	t_in	*input;
	t_table	*table;
	t_philo	**philo;

	input = malloc(sizeof(t_in));
	table = malloc(sizeof(t_table));

	if (f_input_and_table(ac, av, input, table) < 0)
		return (1);
	philo = f_init_philos(input, table);
	if (!philo)
	{
		f_destroy_table(table, input);
		return (printf("ERROR: f_init_philos\n"), 1);
	}
	if (f_init_threads(philo, table->philos) < 0)
	{
		f_destroy_table(table, input);
		philo = f_free_philos(philo);
		return (printf("ERROR: f_init_threads\n"), 1);
	}
	f_join_threads(input, table->philos);
	philo = f_free_philos(philo);
	f_destroy_table(table, input);
}

int f_input_and_table(int ac, char **av, t_in *input, t_table *table)
{
	if (f_manage_input(ac, av, input) < 0)
		return (printf("ERROR: Input\n"), -1);
	if (f_init_table(table, input) < 0)
		return (printf("ERROR: init_table\n"), -1);
	return (0);
}

int f_protected_malloc(void *dest, size_t size)
{
	
}

/*
	input und table mit malloc anlegen --> WICHTIG AM ENDE FREEN
	protected malloc fragen mit void *p
	eventuell init und join threads abändern
	
*/