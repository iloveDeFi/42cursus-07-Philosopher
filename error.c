/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:15:24 by bat               #+#    #+#             */
/*   Updated: 2024/02/05 09:23:19 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("[ERROR] : The number of arguments must be between 5 and 6\n");
		return (1);
	}
	if (argv[1][0] == '0')
	{
		printf("[ERROR] : The number of philosophers must be at least 1\n");
		return (1);
	}
	while (argv[i])
	{
		if (ft_check_digit(argv[i]) == 1)
		{
			printf("Invalid argument: %s. Only positive numbers.\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_digit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < 48 || argv[i] > 57)
			return (1);
		i++;
	}
	return (0);
}