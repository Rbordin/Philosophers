/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:46:13 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/17 14:58:05 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(char *message, t_philo *philo)
{
	ft_printf("%s %s\n", philo, message);
}

void	get_some_rest(t_philo *philo, t_able *table)
{
	ft_printf("%s %s\n", philo, SLEEP);
	usleep(table->sleep_time);
	ft_printf("%s %s\n", philo, THINK);
}