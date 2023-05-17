/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:30:46 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/17 15:39:48 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <sys/_types/_timeval.h>
# include "ft_printf/ft_printf.h"

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				max_meal;
	int				philo_nb;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	t_philo			*philos;
	
}	t_able;

typedef struct s_philo
{
	int				id;
	int				meal_nb;
	int				*left_forks;
	int				*right_forks;
	u_int64_t		d_time;
	u_int64_t		e_time;
	u_int64_t		s_time;
	pthread_t		tid;
	pthread_mutex_t lock;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	t_able			table;
}	t_philo;



//philo.c
u_int64_t	timer(t_able *table);
void		sitting(t_able *table);
void		*routine(t_philo *philo, t_able *table);

//utils.c
int			ft_atoi(const char *str);
int			ft_sign(char c);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);


//setting.c
void		init(t_able *table, char **argv);
void		lay_the_table(t_able *table);
void		welcoming_the_guest(t_able *table);

//extra.c
void	message(char *message, t_philo *philo);
void	get_some_rest(t_philo *philo, t_able *table);

#endif