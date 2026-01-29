/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:53:20 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/29 11:47:24 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		f_init_forks(pthread_mutex_t **forks, int nop);
void	f_destroy_forks(pthread_mutex_t **forks, int nop);

int	    f_init_table(t_table *table, t_in *input)
{
    if (pthread_mutex_init(&table->death, NULL) != 0)
        return (-1);
    if (pthread_mutex_init(&table->log, NULL) != 0)
    {
        pthread_mutex_destroy(&table->death);
        return (-1);
    }
	if (f_init_forks(&table->forks, input->nop) < 0)
    {
        pthread_mutex_destroy(&table->death);
        pthread_mutex_destroy(&table->log);
        return (-1);
    }
    //ich bin hier
    /*
    jetzt: 
    f_init philos genau so protecten wie init forks also bei fehler
    während anlegen while(--i >= 0) -> pthread_join()
    um bereits erstellte/laufende threads wieder einzugliedern
    dann:
    f_join_philos -> um sie am schluss aufzuräumen
    
    */
	return (0);
}

int	    f_init_mutex_array(pthread_mutex_t **array, int nop)
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

/*
VERWENDE: sandbox/forks.c
*/