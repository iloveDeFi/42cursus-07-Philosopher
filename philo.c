/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:15:14 by bat               #+#    #+#             */
/*   Updated: 2024/02/05 10:20:56 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	t_data data;

	if (!ft_check_args(argc, argv))
	{
		ft_init_data_and_args(&data, argv);
		ft_init_philo(&data);
		ft_launch_dinner(&data);
		ft_destroy_mutex(&data);
	}


	return 0;
}