/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:22:26 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/17 10:08:27 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h> //used??

// struct prototypes

typedef struct s_input  t_in;



// function prototypes

// f_utilities.c
long int	f_valid_ulong(const char *s);
size_t		f_slen(const char *s, int print);
int			ft_sncmp(const char *s1, const char *s2, size_t n);

// structs

typedef struct s_input
{
    size_t nop;
    size_t ttd;
    size_t tte;
    size_t tts;
    size_t notepme;
}   t_in;

#endif
