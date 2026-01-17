/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:56:29 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/17 12:20:33 by fsitter          ###   ########.fr       */
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
		input->notepme = f_valid_ulong(av[5]);
	if (input->nop < 1 || input->ttd < 1 || input->tte < 1 || input->tts < 1
		|| input->notepme < 1)
		return (-1);
	return (0);
}
