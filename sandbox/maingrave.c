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

	uint64_t time = f_get_time();

	printf("\nTime Passed: %ld\n", time - input.start_time);
}