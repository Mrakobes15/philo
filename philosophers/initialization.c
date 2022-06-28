/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:27:48 by risolon           #+#    #+#             */
/*   Updated: 2022/06/28 20:10:39 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philo_num)
	{
		param->philo[i].id = i;
		param->philo[i].times_eaten = 0;
		param->philo[i].left_fork = i;
		param->philo[i].right_fork = (i + 1) % param->philo_num;
		param->philo[i].last_meal = 0;
		param->philo[i].param = (struct t_param *)param;
		pthread_mutex_init(&(param->philo[i].ph), NULL);
		i++;
	}
	return (0);
}

int	init_mutex(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philo_num)
	{
		if (pthread_mutex_init(&(param->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(param->meal), NULL))
		return (1);
	if (pthread_mutex_init(&(param->send_message), NULL))
		return (1);
	return (0);
}

int	initialization(t_param *param, int argc, char **argv)
{
	param->philo_num = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->philo_died = 0;
	param->dinner_over = 0;
	if (param->philo_num > 200 || param->philo_num < 0)
	{
		printf("Error! Wrong number of philosophers!\n");
		return (1);
	}
	if (argc == 6)
		param->times_eating = ft_atoi(argv[5]);
	else
		param->times_eating = -1;
	if (init_mutex(param))
		return (2);
	init_philo(param);
	return (0);
}
