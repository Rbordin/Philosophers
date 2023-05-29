/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:46:13 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/29 11:37:17 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(char *message, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write);
	if (ft_strcmp("died!", message) == 0 && philo->table->life_status == 0)
	{
		printf("%llu %d %s\n", (timer() - philo->table->start_time),
			philo->id, message);
		philo->table->life_status = 1;
		meal_is_over(philo->table);
	}
	else
		printf("%llu %d %s\n", (timer() - philo->table->start_time),
			philo->id, message);
	pthread_mutex_unlock(&philo->table->write);
}

void	get_some_rest(t_philo *philo)
{
	message("is sleeping!", philo);
	ft_usleep(philo->table->sleep_time);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = timer();
	while ((timer() - start) < time)
		usleep(time / 10);
	return (0);
}

void	*use_napkins(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (philo->table->life_status == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->table->enough >= philo->table->philo_nb)
			philo->table->life_status = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *) 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}
