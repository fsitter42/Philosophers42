/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:22:26 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/24 10:38:46 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h> // uint64_t
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h> //used?? usleep

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

// f_input.c
int						f_manage_input(int ac, char **av, t_in *input);

// f_time.c
uint64_t				f_get_time(void);

// structs

typedef struct s_input
{
	size_t				nop;
	size_t				ttd;
	size_t				tte;
	size_t				tts;
	int					notepme;
	uint64_t			start_time;
	pthread_mutex_t		*death;
	pthread_mutex_t		*log;
}						t_in;

typedef struct s_philo
{
	size_t				index;
	size_t				ate;
	size_t				alive;
	uint64_t			lte;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_in				*input;
}						t_philo;

#endif