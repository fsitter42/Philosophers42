/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:22:26 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/29 12:44:31 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h> // uint64_t
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h> //used?? usleep

// struct prototypes

typedef struct s_input	t_in;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

// function prototypes

// f_input_utilities.c
long int				f_valid_ulong(const char *s);

// f_input.c
int						f_manage_input(int ac, char **av, t_in *input);

// f_time.c
uint64_t				f_get_time(void);
void					f_sleep(uint64_t ms);

// f_table.c
int						f_init_table(t_table *table, t_in *input);
void					f_destroy_table(t_table *table, t_in *input);

// f_philo_create.c
t_philo					**f_init_philos(t_in *input, t_table *table);
t_philo					**f_free_philos(t_philo **philos);

// f_philo_routine.c
void					*f_philo_routine(void *p);
int						f_is_live(t_philo *philo);

// f_philo_actions.c
void					f_philo_eat(t_philo *philo);
void					f_philo_sleep(t_philo *ph);
void					f_philo_think(t_philo *ph);
void					f_print_status(t_philo *p, char *status);

// f_philo_actions2.c
void					f_take_forks(t_philo *ph, pthread_mutex_t *f1,
							pthread_mutex_t *f2);
void					f_leave_forks(pthread_mutex_t *f1, pthread_mutex_t *f2);

// f_ghost_routine.c
void					*f_ghost_routine(void *p);

// f_threads_create.c
int						f_init_threads(t_philo **ph, pthread_t *threads);
void					f_join_threads(t_in *in, pthread_t *threads);

// structs
typedef struct s_input
{
	size_t				nop;
	size_t				ttd;
	size_t				tte;
	size_t				tts;
	int					notepme;
	uint64_t			start_time;
	bool				life;
	pthread_mutex_t		*live;
	pthread_mutex_t		*log;
}						t_in;

typedef struct s_philo
{
	size_t				index;
	size_t				ate_x_times;
	uint64_t			lte;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*sensor;
	t_in				*input;
}						t_philo;

typedef struct s_table
{
	pthread_mutex_t		*forks;
	pthread_mutex_t		live;
	pthread_mutex_t		log;
	pthread_t			*philos;
	pthread_mutex_t		*sensors;

}						t_table;

#endif