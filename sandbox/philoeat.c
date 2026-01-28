void	f_philo_eat(t_philo *ph)
{
	pthread_mutex_t	*f1;
	pthread_mutex_t	*f2;

	f1 = ph->left_fork;
	f2 = ph->right_fork;
	if (ph->index % 2 == 0)
	{
		f1 = ph->right_fork;
		f2 = ph->left_fork;
	}
	pthread_mutex_lock(f1);
	f_print_status(ph, "has taken a fork");
	pthread_mutex_lock(f2);
	f_print_status(ph, "has taken a fork");
	f_print_status(ph, "is eating");
	pthread_mutex_lock(ph->input->live);
	ph->lte = f_get_time();
	ph->ate_x_times += 1;
	pthread_mutex_unlock(ph->input->live);
	f_sleep(ph->input->tte);
	pthread_mutex_unlock(f2);
	pthread_mutex_unlock(f1);
}