/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_philo_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:51:40 by fsitter           #+#    #+#             */
/*   Updated: 2026/01/25 12:51:49 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */











	// ich bin hier
	/*
	jetzt:
	f_init philos genau so protecten wie init forks also bei fehler
	während anlegen while(--i >= 0) -> pthread_join()
	um bereits erstellte/laufende threads wieder einzugliedern
	dann:
	f_join_philos -> um sie am schluss aufzuräumen
	*/