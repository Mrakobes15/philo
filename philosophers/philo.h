/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:40 by risolon           #+#    #+#             */
/*   Updated: 2022/06/28 20:07:42 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>

struct	s_param;

typedef struct s_philosopher
{
	int					id;
	int					times_eaten;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	struct t_param		*param;
	pthread_t			thread_id;
	pthread_mutex_t		ph;
}	t_philosopher;

typedef struct s_param
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_eating;
	int				philo_died;
	int				dinner_over;
	long long		timeline;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	meal;
	pthread_mutex_t	send_message;
	t_philosopher	philo[200];
}	t_param;


/* utils.c */
int			print_message(t_param *param, int philo_id, char *str);
int			ft_atoi(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(char c);
int			ft_isspace(char c);
/* time_utils.c */
long long	timestamp(void);
long long	difference(long long t1, long long t2);
void		pass_the_time(long long time, t_param *param);
/* initializatiom.c */
int			initialization(t_param *param, int argc, char **argv);
int			init_mutex(t_param *param);
int			init_philo(t_param *param);
/* algorythm.c */
int			start(t_param *param);
void		check_death(t_param *pa, t_philosopher *ph);
void		philo_eating(t_param *param, t_philosopher *void_philo);
void		*thread_func(void *void_philo);
void		finish(t_param *param, t_philosopher *philo);
#endif