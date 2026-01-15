/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utilities.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:20:55 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/15 16:20:31 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

size_t	f_strlen(const char *s, int print)
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

long int	f_valid_ulong(const char *s)
{
	char *longmax = "9223372036854775807";
	while ((*s >= 9 && *s <= 13) || (*s == 32))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			return (-1);
		s++;
	}
	if (f_strlen(s, 0) > 19 || f_strlen(s, 0) == 19 && ft_strncmp(s, longmax, 19) > 0)
		return (-1);
	return (1);
}
