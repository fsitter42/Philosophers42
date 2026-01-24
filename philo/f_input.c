/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:56:29 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/24 13:46:40 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	f_manage_input(int ac, char **av, t_in *input)
{
	if ((ac < 5) || (ac > 6))
		return (-1);
	input->nop = f_valid_ulong(av[1]);
	input->ttd = f_valid_ulong(av[2]);
	input->tte = f_valid_ulong(av[3]);
	input->tts = f_valid_ulong(av[4]);
	if (ac == 6)
	{
		input->notepme = f_valid_ulong(av[5]);
		if (input->notepme < 1)
			return (-1);
	}
	else
		input->notepme = -1;
	if (input->nop < 1 || input->ttd < 1 || input->tte < 1 || input->tts < 1)
		return (-1);
	input->start_time = f_get_time();
	return (0);
}

/*
line 30: set to -1; bc then i can: 
if (notepme > 0) {i = 0; while (i < notepme) {do x}}
*/