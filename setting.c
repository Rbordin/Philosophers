/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:18:18 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/29 11:37:02 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lay_the_table(t_able *table)
{
	int	i;

	i = -1;
	table->forks = ft_calloc(table->philo_nb, sizeof(pthread_mutex_t));
	if (!table->forks)
		exit(1);
	while (++i < table->philo_nb)
		pthread_mutex_init(&table->forks[i], NULL);
	table->philos[0].left_fork = &table->forks[0];
	table->philos[0].right_fork = &table->forks[table->philo_nb - 1];
	i = 0;
	while (++i < table->philo_nb)
	{
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[i - 1];
	}
}

void	welcoming_the_guests(t_able *table)
{
	int	i;

	i = 0;
	table->start_time = timer();
	table->philos = ft_calloc(table->philo_nb, sizeof(t_philo));
	lay_the_table(table);
	while (i < table->philo_nb)
	{
		table->philos[i].table = table;
		table->philos[i].id = i + 1;
		table->philos[i].d_time = table->death_time;
		table->philos[i].eating = 0;
		table->philos[i].meal_nb = 0;
		table->philos[i].start_eating = timer();
		pthread_mutex_init(&table->philos[i].lock, NULL);
		i++;
	}
}

void	table_init(t_able *table, char **argv)
{
	table->philo_nb = ft_atoi(argv[1]);
	table->death_time = (u_int64_t)ft_atoi(argv[2]);
	table->eat_time = (u_int64_t)ft_atoi(argv[3]);
	table->sleep_time = (u_int64_t)ft_atoi(argv[4]);
	if (table->philo_nb <= 0 || table->philo_nb > 200 || table->eat_time < 0
		|| table->death_time < 0 || table->sleep_time < 0)
		print_error("getting datas\n");
	table->life_status = 0;
	table->enough = 0;
	pthread_mutex_init(&table->write, NULL);
	pthread_mutex_init(&table->lock, NULL);
	table->thread = ft_calloc(table->philo_nb, sizeof(pthread_t));
	if (!table->thread)
		print_error("allocating threads\n");
}

void	sitting(t_able *table)
{
	int			i;
	pthread_t	meal_counter;

	welcoming_the_guests(table);
	if (table->max_meal > 0)
	{
		if ((pthread_create(&meal_counter, NULL, &use_napkins,
					&table->philos[0]) != 0))
			print_error("error checking use_napkins\n");
	}
	i = -1;
	while (++i < table->philo_nb)
	{
		if ((pthread_create(&table->thread[i], NULL,
					&routine, &table->philos[i])) != 0)
			print_error("creating threads\n");
		ft_usleep(1);
	}
	i = -1;
	while (++i < table->philo_nb)
	{
		if ((pthread_join(table->thread[i], NULL)) != 0)
			print_error("error joining threads\n");
	}
}

void	*fate(void *filo)
{
	t_philo	*philo;

	philo = (t_philo *) filo;
	while (philo->table->life_status == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (((timer() - philo->start_eating) >= philo->d_time)
			&& philo->eating == 0)
			message("died!", philo);
		if (philo->meal_nb == philo->table->max_meal)
		{
			pthread_mutex_lock(&philo->table->lock);
			philo->table->enough++;
			philo->meal_nb++;
			pthread_mutex_unlock(&philo->table->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *) 0);
}
