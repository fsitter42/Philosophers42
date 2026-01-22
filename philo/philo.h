/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:22:26 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/22 14:59:02 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h> //used??
# include <stdint.h> // uint64_t

// struct prototypes

typedef struct s_input	t_in;
typedef struct s_philo	t_philo;

// function prototypes

// f_input_utilities.c
long int				f_valid_ulong(const char *s);
size_t					f_slen(const char *s, int print);
int						ft_sncmp(const char *s1, const char *s2, size_t n);
int						ft_isdigit(int c);
size_t					f_nan(const char *s);

// f.input.c

int						f_manage_input(int ac, char **av, t_in *input);

// structs

typedef struct s_input
{
	size_t				nop;
	size_t				ttd;
	size_t				tte;
	size_t				tts;
	size_t				notepme;
	uint64_t			start_time;
	pthread_mutex_t		*dead;
	pthread_mutex_t		*log;
}						t_in;

typedef struct s_philo
{
	size_t				index;
}	t_philo;


#endif
