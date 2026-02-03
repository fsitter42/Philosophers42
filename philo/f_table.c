/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:53:20 by fsitter           #+#    #+#             */
/*   Updated: 2026/02/03 09:02:25 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		f_init_mutex_array(pthread_mutex_t **array, int nop);
void	f_destroy_mutex_array(pthread_mutex_t **array, int nop);

int	f_init_table(t_table *table, t_in *input)
{
	if (pthread_mutex_init(&table->live, NULL) != 0)
		return (-1);
	input->live = &(table->live);
	if (pthread_mutex_init(&table->log, NULL) != 0)
		return (f_destroy_table(table, input), -1);
	input->log = &(table->log);
	if (pthread_mutex_init(&table->open, NULL) != 0)
		return (f_destroy_table(table, input), -1);
	input->open = &(table->open);
	if (f_init_mutex_array(&table->forks, input->nop) < 0)
		return (f_destroy_table(table, input), -1);
	if (f_init_mutex_array(&table->sensors, input->nop) < 0)
		return (f_destroy_table(table, input), -1);
	table->philos = malloc(sizeof(pthread_t) * (input->nop + 1));
	if (!table->philos)
		return (f_destroy_table(table, input), -1);
	return (0);
}

void	f_destroy_table(t_table *table, t_in *input)
{
	if (input->live)
	{
		pthread_mutex_destroy(&table->live);
		input->live = NULL;
	}
	if (input->log)
	{
		pthread_mutex_destroy(&table->log);
		input->log = NULL;
	}
	if (input->open)
	{
		pthread_mutex_destroy(&table->open);
		input->open = NULL;
	}
	f_destroy_mutex_array(&table->forks, input->nop);
	f_destroy_mutex_array(&table->sensors, input->nop);
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
	return ;
}

void	f_destroy_mutex_array(pthread_mutex_t **array, int nop)
{
	int	i;

	if (!array || !*array)
		return ;
	i = 0;
	while (i < nop)
	{
		pthread_mutex_destroy(&(*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
	return ;
}

int	f_init_mutex_array(pthread_mutex_t **array, int nop)
{
	int	i;

	*array = malloc(sizeof(pthread_mutex_t) * nop);
	if (!*array)
		return (-1);
	i = 0;
	while (i < nop)
	{
		if (pthread_mutex_init(&(*array)[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(*array)[i]);
			free(*array);
			*array = NULL;
			return (-1);
		}
		i++;
	}
	return (0);
}
