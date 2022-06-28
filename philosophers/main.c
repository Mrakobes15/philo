/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risolon <risolon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:18:44 by risolon           #+#    #+#             */
/*   Updated: 2022/06/28 17:40:27 by risolon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) || (ft_atoi(str) < 0))
		{
			ft_putstr_fd("Wrong argument - ", 1);
			ft_putstr_fd(str, 1);
			ft_putstr_fd("\n", 1);
			exit (1);
		}
		i++;
	}
}

int	error_managment(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Wrong number of arguments!\n", 1);
		exit (1);
	}
	i = 1;
	while (i < argc)
	{
		check_args(argv[i]);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_param	param;

	error_managment(argc, argv);
	initialization (&param, argc, argv);
	start(&param);
	return (0);
}
