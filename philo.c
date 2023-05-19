/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:30:03 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/19 14:33:32 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int 	i;
	t_able	table;
	
	i = 0;
	if (argc < 5 || argc > 6)
		return (1);
	if (argc == 6)
		table.max_meal = ft_atoi(argv[5]);
	printf("1\n");
	table_init(&table, argv);
	sitting(&table);
	
	return (0);
}

void	sitting(t_able *table)
{
	int	i;

	i = -1;
	printf("1\n");

	welcoming_the_guests(table);
	while (++i < table->philo_nb)
		pthread_create(&table->philos[i].tid, NULL, &routine, &table->philos[i]);
	i = -1;
	while (++i <= table->philo_nb)
		pthread_join(table->philos[i].tid, NULL);

}

u_int64_t	timer()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}

void	*routine(void *args)
{
	t_philo *philo;

	philo = (t_philo *) args;
	printf("id = %d\n", philo->id);
	while (philo->table->life_status == 0)
		eat(philo, philo->table->eat_time);
	printf("routine\n");
	if (pthread_join(philo->tid, NULL))
		return ((void *)1);
	return ((void *)0);
}

void	eat(t_philo *philo, u_int64_t eat_time)
{
	if (philo->status == 0)
		pthread_mutex_lock(philo->right_fork);
	philo->status = 1;
	if (philo->status == 1)
		pthread_mutex_lock(philo->left_fork);
	philo->status = 2;
	message("is eating!", philo);
	if (philo->status == 2)
		usleep(eat_time);
	philo->e_time = timer();
	philo->status = 3;
	if (philo->status == 3)
		pthread_mutex_unlock(philo->right_fork);
	if (philo->status == 4)
		pthread_mutex_unlock(philo->left_fork);
	philo->status = 5;
	if (philo->status == 5)
		get_some_rest(philo, philo->table);
}
	
	