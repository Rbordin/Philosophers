/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:46:13 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/19 12:16:27 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(char *message, t_philo *philo)
{
	ft_printf("philosopher %d %s\n", philo->id, message);
}

void	get_some_rest(t_philo *philo, t_able *table)
{
	ft_printf("%s %s\n", philo, SLEEP);
	usleep(table->sleep_time);
	if (table->death_time < philo->e_time + (timer() - philo->e_time))
		death(philo);
	else
		ft_printf("philosopher %d %s\n", philo->id, THINK);
}

void	death(t_philo *philo)
{
	message(DEATH, philo);
	exit (1);
}
