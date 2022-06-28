/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:15:24 by risolon           #+#    #+#             */
/*   Updated: 2022/06/28 20:09:51 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_param *param)
{
	int				i;
	t_philosopher	*philo;

	i = 0;
	philo = param->philo;
	param->timeline = timestamp();
	while (i < param->philo_num)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, thread_func, &philo[i]))
			return (1);
		philo[i].last_meal = timestamp();
		i++;
	}
	check_death(param, philo);
	finish(param, philo);
	return (0);
}

void	check_death(t_param *pa, t_philosopher *ph)
{
	int	i;

	while (!(pa->dinner_over))
	{
		i = -1;
		while (++i < pa->philo_num && pa->philo_died == 0)
		{
			pthread_mutex_lock(&(ph->ph));
			pthread_mutex_lock(&(pa->meal));
			if (difference(ph[i].last_meal, timestamp()) >= pa->time_to_die)
			{
				print_message(pa, i, "has passed away. RIP\n");
				pa->philo_died = 1;
			}
			pthread_mutex_unlock(&(pa->meal));
			pthread_mutex_unlock(&(ph->ph));
			usleep(100);
		}
		if (pa->philo_died)
			break ;
		i = 0;
		while (pa->times_eating != -1 && i < pa->philo_num
			&& ph[i].times_eaten > pa->times_eating)
			i++;
		if (i == pa->philo_num)
			pa->dinner_over = 1;
	}
}

void	philo_eating(t_param *param, t_philosopher *philo)
{
	pthread_mutex_lock(&(param->forks[philo->left_fork]));
	print_message(param, philo->id, " has taken left fork.");
	pthread_mutex_lock(&(param->forks[philo->right_fork]));
	print_message(param, philo->id, " has taken right fork.");
	pthread_mutex_lock(&(param->meal));
	print_message(param, philo->id, " is eating.");
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&(param->meal));
	pass_the_time(param->time_to_eat, param);
	philo->times_eaten += 1;
	pthread_mutex_unlock(&(param->forks[philo->left_fork]));
	pthread_mutex_unlock(&(param->forks[philo->right_fork]));
}

void	*thread_func(void *void_philo)
{
	t_philosopher	*philo;
	t_param			*param;

	philo = (t_philosopher *)void_philo;
	param = (t_param *)philo->param;
	if (philo->id % 2)
		usleep(500);
	while (!(param->philo_died))
	{
		philo_eating(param, philo);
		if (param->dinner_over)
			break ;
		print_message(param, philo->id, " is sleeping.");
		pass_the_time(param->time_to_sleep, param);
		print_message(param, philo->id, " is thinking.");
	}
	return (NULL);
}

void	finish(t_param *param, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < param->philo_num)
	{
		pthread_join(philo[i].thread_id, NULL);
		pthread_mutex_destroy(&(philo->ph));
		i++;
	}
	i = 0;
	while (i < param->philo_num)
	{
		pthread_mutex_destroy(&(param->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(param->send_message));
	pthread_mutex_destroy(&(param->meal));
	if (param->philo_died)
		printf("Philosopher has died! Looks like he's not so smart afterall.\n");
	if (param->dinner_over)
		printf("Philos have finished eating. Go to the jym now, you are fat.\n");
}
