/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a600 <a600@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:11:09 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/29 23:51:18 by a600             ###   ########.fr       */
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
	if (!input)
		return (1);
	table = malloc(sizeof(t_table));
	if (!table)
		return (free(input), 1);
	if (f_input_and_table(ac, av, input, table) < 0)
		return (free(input), free(table), 1);
	philo = f_init_philos(input, table);
	if (!philo)
		return (f_destroy_table(table, input), 1);
	if (f_init_threads(philo, table->philos) < 0)
	{
		philo = f_free_philos(philo);
		return (f_destroy_table(table, input), 1);
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

/*
	input und table mit malloc anlegen --> WICHTIG AM ENDE FREEN
	protected malloc fragen mit void *p
	eventuell init und join threads abändern
	
*/