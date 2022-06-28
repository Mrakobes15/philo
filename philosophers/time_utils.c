/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:46:25 by risolon           #+#    #+#             */
/*   Updated: 2022/06/28 16:58:34 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	difference(long long t1, long long t2)
{
	return (t2 - t1);
}

void	pass_the_time(long long time, t_param *param)
{
	long long	i;

	i = timestamp();
	while (!(param->philo_died))
	{
		if (difference(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}
