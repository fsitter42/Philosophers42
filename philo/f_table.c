/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:53:20 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/25 15:37:09 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		f_init_forks(t_table *table, int nop);
void	f_destroy_forks(t_table *table, int nop);

int	f_init_table(t_table *table, t_in *input)
{
	if (pthread_mutex_init(&table->live, NULL) != 0)
		return (-1);
	input->live = &(table->live);
	if (pthread_mutex_init(&table->log, NULL) != 0)
	{
		pthread_mutex_destroy(&table->live);
		input->live = NULL;
		return (-1);
	}
	input->log = &(table->log);
	if (f_init_forks(table, input->nop) < 0)
	{
		pthread_mutex_destroy(&table->live);
		pthread_mutex_destroy(&table->log);
		input->live = NULL;
		input->log = NULL;
		return (-1);
	}
	return (0);
}

int	f_init_forks(t_table *table, int nop)
{
	int	i;

	table->forks = NULL;
	table->forks = malloc(sizeof(pthread_mutex_t) * nop);
	if (!table->forks)
		return (-1);
	i = 0;
	while (i < nop)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->forks[i]);
			free(table->forks);
			table->forks = NULL;
			return (-1);
		}
		i++;
	}
	return (0);
}

void	f_destroy_forks(t_table *table, int nop)
{
	int	i;

	if (!table || !table->forks)
		return ;
	i = 0;
	while (i < nop)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
	table->forks = NULL;
	return ;
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
	f_destroy_forks(table, input->nop);
	return ;
}
/*
zeile 37
ACHTUNG:
f_destroy_table soll f_destroy_mv() werden, in der die beiden extra mutex
zerstört werden und die forks

dabei wichtig: wenn die threads erstellt sind müssen die zuerst gejoint werden
befor die jetztige f_destroy_table gerufen wird

änderungsvorschalg:

struct metaverse{struct table, struct ether}

struct table{forks, philos}
struct ether{log, life/death}

NOTES:
schaue auch ~/Desktop/notes.txt

*/

/*
DONE:allocate mem for forks
DONE:initalize death and log
DONE:initialize forks one by one

DONE: destroy mutexes

NEXT: allocate mem for philos SIEHE Zeile 33

build shit to free all of that

should return -1 on error
*/