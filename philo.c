/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:34:55 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/29 11:45:07 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	timer(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	if ((pthread_create(&philo->tid, NULL, &fate, (void *)philo)) != 0)
		print_error("error checking fate of a philosopher\n");
	while (philo->table->life_status == 0)
	{
		eat(philo);
		message("is thinking!", philo);
	}
	if ((pthread_join(philo->tid, NULL) != 0))
		print_error("error joining fate of a philosopher\n");
	return ((void *)0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	message("took a fork right!", philo);
	pthread_mutex_lock(philo->left_fork);
	message("took a fork left!", philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->start_eating = timer();
	message("is eating!", philo);
	philo->meal_nb++;
	ft_usleep(philo->table->eat_time);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	get_some_rest(philo);
}

void	meal_is_over(t_able *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].lock);
	}
	pthread_mutex_destroy(&table->write);
	pthread_mutex_destroy(&table->lock);
	free(table->thread);
	free(table->forks);
	free(table->philos);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_able	table;

	if (argc < 5 || argc > 6)
		return (1);
	table.max_meal = -1;
	if (argc == 6)
		table.max_meal = ft_atoi(argv[5]);
	table_init(&table, argv);
	sitting(&table);
	meal_is_over(&table);
	return (0);
}
