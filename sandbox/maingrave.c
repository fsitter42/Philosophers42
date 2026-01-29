#include "../philo/philo.h"

// input
int	main(int ac, char **av)
{
	t_in	input;

	if (f_manage_input(ac, av, &input) < 0)
		return (printf("ERROR: Input\n"), 1);
	input.start_time = f_get_time();

	printf("%zu\n", input.nop);
	printf("%zu\n", input.ttd);
	printf("%zu\n", input.tte);
	printf("%zu\n", input.tts);
	printf("%i\n", input.notepme);
}

//f_sleep
int	main(int ac, char **av)
{
	t_in	input;

	if (f_manage_input(ac, av, &input) < 0)
		return (printf("ERROR: Input\n"), 1);
	input.start_time = f_get_time();
	
	//usleep(400000);
	f_sleep(400);
	uint64_t time = f_get_time();
	printf("\nTime Passed: %ld\n", time - input.start_time);
}

//f_table.c -> valgrind --tool=helgrind ./a.out 6 2 2 2
int	main(int ac, char **av)
{
	t_in	input;
	t_table	table;
	t_philo	**philo;

	if (f_manage_input(ac, av, &input) < 0)
		return (printf("ERROR: Input\n"), 1);
	if (f_init_table(&table, &input) < 0)
		return (printf("ERROR: init_table\n"), 1);
	

	printf("LIVE: %p\n", input.live);
	printf("LOG: %p\n", input.log);
	printf("FORKS: %p\n", table.forks);
	printf("FORK1: %p\n", (void *)&table.forks[1]);
	
	f_destroy_table(&table, &input);
	printf("nachher\n");
	printf("LIVE: %p\n", input.live);
	printf("LOG: %p\n", input.log);
	printf("FORKS: %p\n", table.forks);
	printf("FORK1: %p\n", (void *)&table.forks[1]);	
}

int	main(int ac, char **av)
{
	t_in	input;
	t_table	table;
	t_philo	**philo;

	if (f_manage_input(ac, av, &input) < 0)
		return (printf("ERROR: Input\n"), 1);
	if (f_init_table(&table, &input) < 0)
		return (printf("ERROR: init_table\n"), 1);
	philo = f_init_philos(&input, &table);
	if (!philo)
	{
		printf("ERROR: f_init_philos\n");
		f_destroy_table(&table, &input);
		return (1);
	}
	if (f_init_threads(philo, table.philos) < 0)
	{
		printf("ERROR: f_init_threads\n");
		f_destroy_table(&table, &input);
		philo = f_free_philos(philo);
		return (1);
	}
	f_join_threads(input, table.philos);
	philo = f_free_philos(philo);
	f_destroy_table(&table, &input);
}

int main(int ac, char **av)
{
	t_in	*input;
	t_table	*table;
	int i;

	i = 0;
	input = malloc(sizeof(t_in));
	if (!input)
		return (1);
	if (f_manage_input(ac, av, &input) < 0)
		return (printf("ERROR: Input\n"), free(input), 1);
	table = malloc(sizeof(t_table));
	if (!table)
		return (free(input), 2);
	if (f_init_table(&table, &input) < 0)
		return (printf("ERROR: init_table\n"), free(input), free(table), 1);
	if (mein(input, table) < 0)
		i = 3;
	return(free(input), free(table), i);
}

int	mein(t_in *input, t_table *table)
{
	t_philo	**philo;
	
	
	philo = f_init_philos(&input, &table);
	if (!philo)
	{
		f_destroy_table(&table, &input);
		return (-1);
	}
	if (f_init_threads(philo, table->philos) < 0)
	{
		philo = f_free_philos(philo);
		f_destroy_table(&table, &input);
		return (-1);
	}
	f_join_threads(input, table->philos);
	philo = f_free_philos(philo);
	f_destroy_table(&table, &input);
	return (0);
}
