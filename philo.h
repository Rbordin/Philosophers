/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:30:46 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/19 14:27:32 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEATH "is death"

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
	int				life_status;
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
	int				status;
	int				*left_forks;
	int				*right_forks;
	u_int64_t		d_time;
	u_int64_t		e_time;
	u_int64_t		s_time;
	pthread_t		tid;
	pthread_mutex_t lock;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	t_able			*table;
}	t_philo;



//philo.c
u_int64_t	timer();
void		sitting(t_able *table);
void		*routine(void *args);
void		eat(t_philo *philo, u_int64_t eat_time);

//utils.c
int			ft_atoi(const char *str);
void		print_error(void);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_is_digit(char c);


//setting.c
void		table_init(t_able *table, char **argv);
void		lay_the_table(t_able *table);
void		welcoming_the_guests(t_able *table);

//extra.c
void		message(char *message, t_philo *philo);
void		get_some_rest(t_philo *philo, t_able *table);
void		death(t_philo *philo);

#endif