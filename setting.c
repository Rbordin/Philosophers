/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:18:18 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/12 11:18:14 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lay_the_table(t_able *table)
{
	int	i;

	i = -1;
	table->forks = ft_calloc(table->philo_nb, sizeof(pthread_mutex_t));
	while (++i < table->philo_nb)
		pthread_mutex_init(&table->forks[i], NULL);
	table->philos[0].left_fork = &table->forks[0];
	table->philos[0].right_fork = &table->forks[table->philo_nb - 1];
	i = 1;
	while (i < table->philo_nb)
	{
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[i - 1];
		i++;
	}
}

void	welcoming_the_guest(t_able *table)
{
	int	i;

	i = 0;
	table->philos = ft_calloc(table->philo_nb, sizeof(t_philo));
	while (i < table->philo_nb)
	{
		table->philos->id = i;
		table->philos->d_time = table->death_time;
		table->philos->e_time = 0;
		table->philos->s_time = 0;
		pthread_mutex_init(&table->philos[i].lock, NULL);
		i++;
	}
	lay_the_table(table);
}

void	init(t_able *table, char **argv)
{
	table->philo_nb = ft_atoi(argv[1]);
	table->death_time = (u_int64_t)ft_atoi(argv[2]);
	table->eat_time = (u_int64_t)ft_atoi(argv[3]);
	table->sleep_time = (u_int64_t)ft_atoi(argv[4]);
	table->start_time = timer(table);
	if (table->philo_nb <= 0 || table->philo_nb > 200 || table->eat_time < 0
		|| table->death_time < 0 || table->sleep_time < 0 )
		exit (1);
	sitting(table);

}