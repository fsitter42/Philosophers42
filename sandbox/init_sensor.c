#include "../philo/philo.h"

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

int	f_init_sensors(t_table *table, int nop)
{
	int	i;

	table->sensors = NULL;
	table->sensors = malloc(sizeof(pthread_mutex_t) * nop);
	if (!table->sensors)
		return (-1);
	i = 0;
	while (i < nop)
	{
		if (pthread_mutex_init(&table->sensors[i], NULL) != 0)
		{
			f_destroy_forks(table, i);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	f_destroy_sensors(t_table *table, int nop)
{
	int	i;

	if (!table || !table->sensors)
		return ;
	i = 0;
	while (i < nop)
	{
		pthread_mutex_destroy(&table->sensors[i]);
		i++;
	}
	free(table->sensors);
	table->sensors = NULL;
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
	f_destroy_sensors(table, input->nop);
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
	return ;
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
			f_destroy_forks(table, i);
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
