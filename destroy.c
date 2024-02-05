/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:25:37 by bbessard          #+#    #+#             */
/*   Updated: 2024/02/05 10:10:21 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numberOfPhilo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->eating_locker);
	pthread_mutex_destroy(&data->dead_locker);
	pthread_mutex_destroy(&data->end_locker);
	pthread_mutex_destroy(&data->sasieted_locker);
}
