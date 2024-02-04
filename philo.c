/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:15:14 by bat               #+#    #+#             */
/*   Updated: 2024/02/04 17:58:17 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char argv[])
{
	t_data data;

	ft_check_args(argc, argv);
	ft_init_data();
	ft_init_philo();
	ft_launch_dinner();
	ft_destroy_mutex();

	return 0;
}