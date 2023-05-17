/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:30:03 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/17 15:40:42 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int 	i;
	t_able	table;
	
	i = 0;
	if (argc < 5)
		return (0);
	if (argc == 6)
		table.max_meal = ft_atoi(argv[5]);
	init(&table, argv);
	
}

void	sitting(t_able *table)
{
	int	i;

	i = 0;
	welcoming_the_guest(table);
	while (i <= table->philo_nb)
	{
		pthread_create(&table->philos[i].tid, NULL, &routine, ((void *)(table->philos[i], table)));
		i++;
	}
}

u_int64_t	timer(t_able *table)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}

void	*routine(t_philo *philo, t_able *table)
{
	eat(philo, table->eat_time);
	get_some_rest(philo, table);
}

void	eat(t_philo *philo, u_int64_t eat_time)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	usleep(eat_time);
	message(EAT, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}