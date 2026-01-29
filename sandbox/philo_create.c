#include "../philo/philo.h"

void	f_fill_philos(t_philo *ph, int i, t_in *in, t_table *table)
{
	ph->index = i + 1;
	ph->ate_x_times = 0;
	ph->lte = in->start_time;
	ph->input = in;
	if (i == 0)
		ph->left_fork = &table->forks[in->nop - 1];
	else
		ph->left_fork = &table->forks[i - 1];
	ph->right_fork = &table->forks[i];
	ph->sensor = &table->sensors[i];
	return ;
}

void	f_fill_philos(t_philo *ph, int i, t_in *in, pthread_mutex_t *forks)
{
	ph->index = i + 1;
	ph->ate_x_times = 0;
	ph->lte = in->start_time;
	ph->input = in;
	if (i == 0)
		ph->left_fork = &forks[in->nop - 1];
	else
		ph->left_fork = &forks[i - 1];
	ph->right_fork = &forks[i];
	return ;
}

t_philo	**f_init_philos(t_in *input, t_table *table)
{
	int		i;
	t_philo	**philos;

	i = 0;
	philos = malloc(sizeof(t_philo *) * (input->nop + 1));
	if (!philos)
		return (NULL);
	while (i < input->nop)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			while (--i >= 0)
				free(philos[i]);
			free(philos);
			philos = NULL;
			return (philos);
		}
		f_fill_philos(philos[i], i, input, table);
		i++;
	}
	philos[i] = NULL;
	return (philos);
}

t_philo	**f_init_philos(t_in *input, pthread_mutex_t *forks)
{
	int		i;
	t_philo	**philos;

	i = 0;
	philos = malloc(sizeof(t_philo *) * (input->nop + 1));
	if (!philos)
		return (NULL);
	while (i < input->nop)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			while (--i >= 0)
				free(philos[i]);
			free(philos);
			philos = NULL;
			return (philos);
		}
		f_fill_philos(philos[i], i, input, forks);
		i++;
	}
	philos[i] = NULL;
	return (philos);
}