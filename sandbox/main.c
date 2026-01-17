// f_valid_ulong test

int main(void)
{
	t_in input;
	
	// if (ac != 5 || ac != 6)
	// 	return (-1);
	char *longmax = "  \t 9223372036854775807";
	
	long n = f_valid_ulong(longmax);
	if(n == -1)
		printf("overflow or negative\n");
	else
		printf("%lu\n", n);
	
	
}