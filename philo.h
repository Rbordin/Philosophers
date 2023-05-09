/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:30:46 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/09 15:39:34 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				max_meal;
	int				*left_forks;
	int				*right_forks;
	u_int64_t		d_time;
	u_int64_t		e_time;
	u_int64_t		s_time;
	pthread_mutex_t lock;
	pthread_mutex_t right_fork;
	pthread_mutex_t left_fork;
	
}	t_philo;

typedef struct s_table
{
	int				philo_nb;
	t_philo			*philo;
	
}	t_able;

//philo.c
void	init(t_able *table, char *argv1);

//utils.c
int	ft_atoi(const char *str);
int	ft_sign(char c);


#endif