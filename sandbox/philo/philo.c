/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:11:09 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/30 13:04:27 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mein(t_in *input, t_table *table);

int	main(int ac, char **av)
{
	t_in	*input;
	t_table	*table;
	int		i;

	i = 0;
	input = malloc(sizeof(t_in));
	if (!input)
		return (1);
	if (f_manage_input(ac, av, input) < 0)
		return (printf("ERROR: Input\n"), free(input), 1);
	table = malloc(sizeof(t_table));
	if (!table)
		return (free(input), 2);
	if (f_init_table(table, input) < 0)
		return (printf("ERROR: init_table\n"), free(input), free(table), 3);
	if (mein(input, table) < 0)
		i = 4;
	return (free(input), free(table), i);
}

int	mein(t_in *input, t_table *table)
{
	t_philo	**philo;

	philo = f_init_philos(input, table);
	if (!philo)
	{
		f_destroy_table(table, input);
		return (-1);
	}
	if (f_init_threads(philo, table->philos) < 0)
	{
		philo = f_free_philos(philo);
		f_destroy_table(table, input);
		return (-1);
	}
	f_join_threads(input, table->philos);
	philo = f_free_philos(philo);
	f_destroy_table(table, input);
	return (0);
}
