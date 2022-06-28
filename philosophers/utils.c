/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:58:01 by risolon           #+#    #+#             */
/*   Updated: 2022/06/28 17:50:14 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_message(t_param *param, int philo_id, char *str)
{
	pthread_mutex_lock(&(param->send_message));
	if (!(param->philo_died))
	{
		printf("%lli", timestamp() - param->timeline);
		printf (" %d ", philo_id);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(param->send_message));
	return (0);
}

int	ft_atoi(char *str)
{
	long			res;
	long			minus;
	unsigned int	i;

	res = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res > 2147483648 && minus == -1)
			return (0);
		if (res > 2147483647 && minus == 1)
			return (-1);
	}
	return ((int)(res * minus));
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == '\v'
		|| c == ' ' || c == '\r' || c == '\f');
}
