/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:30:34 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/09 15:41:18 by rbordin          ###   ########.fr       */
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
	init(&table.philo, argv[1]);
	while (i <= &table.philo_nb)
	{
		pthread_create(&table.philo, NULL, &routine, &table.philo);
		i++;
	}
}

void	init(t_able *table, char *argv1)
{
	table->philo_nb = ft_atoi(argv1);
	sitting(table);
	timer(table->philo);
	pthread_mutex_init(&table->philo->lock, NULL);
	pthread_mutex_init(&table->philo->right_fork, NULL);
	pthread_mutex_init(&table->philo->left_fork, NULL);

}

void	sitting(t_able *table)
{
	int	i;

	i = 0;
	while (i <= table->philo_nb)
	{
		pthread_create(&table->philo, NULL, &routine, &table->philo[i]);
		i++;
	}
}

void	timer(t_philo *ari)
{
	gettimeofday();
}

void	*routine(t_philo *ari)
{
	
}