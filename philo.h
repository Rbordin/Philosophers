/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:30:46 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/26 15:53:47 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <sys/_types/_timeval.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				max_meal;
	int				philo_nb;
	int				life_status;
	int				enough;
	pthread_t		*thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	lock;
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
	int				eating;
	u_int64_t		d_time;
	u_int64_t		start_eating;
	pthread_t		tid;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_able			*table;
}	t_philo;

//philo.c
u_int64_t	timer(void);
void		*routine(void *args);
void		eat(t_philo *philo);
void		meal_is_over(t_able *table);

//utils.c
int			ft_atoi(const char *str);
void		print_error(char *str);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_is_digit(char c);

//setting.c
void		table_init(t_able *table, char **argv);
void		lay_the_table(t_able *table);
void		welcoming_the_guests(t_able *table);
void		*fate(void *filo);
void		sitting(t_able *table);

//extra.c
void		message(char *message, t_philo *philo);
void		get_some_rest(t_philo *philo);
int			ft_usleep(useconds_t time);
void		*use_napkins(void *arg);
int			ft_strcmp(char *s1, char *s2);

#endif