/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_input_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:20:55 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/17 11:55:33 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

size_t	f_slen(const char *s, int print)
{
	size_t	i;

	i = 0;
	if (s == NULL || !s || !*s)
		return (i);
	while (s[i] != '\0')
	{
		if (print)
			write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	f_nan(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

long int	f_valid_ulong(const char *s)
{
	long	number;
	char	*lmax;
	size_t	len;

	number = 0;
	lmax = "9223372036854775807";
	len = f_slen(s, 0);
	if (f_nan(s))
		return (0);
	while ((*s >= 9 && *s <= 13) || (*s == 32))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			return (0);
		s++;
	}
	if (len > 19 || len == 19 && ft_sncmp(s, lmax, 19) > 0)
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		number = number * 10 + *s - 48;
		s++;
	}
	return (number);
}
