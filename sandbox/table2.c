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
	table->philos = malloc(sizeof(pthread_t) * input->nop);
	if (!table->philos)
    {
		f_destroy_table(table, input);
		return (-1);
	}
	return (0);
}
