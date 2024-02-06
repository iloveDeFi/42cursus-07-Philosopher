/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:10:05 by bat               #+#    #+#             */
/*   Updated: 2024/02/06 16:16:22 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numberOfPhilo)
	{
		data->philosophers[i].philoID = i + 1;
		data->philosophers[i].data = data;
		data->philosophers[i].rightForkID = i;
		data->philosophers[i].leftForkID = (i + 1) % data->numberOfPhilo;
		data->philosophers[i].numberOfMealEaten = 0;
		data->philosophers[i].state = THINK;
		i++;
	}
}

void	ft_init_data_and_args(t_data *data, char *argv[])
{
	int	i;

	data->numberOfPhilo = ft_atoi(argv[1]);
	data->timeToDie = ft_atoi(argv[2]);
	data->timeToEat = ft_atoi(argv[3]);
	data->timeToSleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->numberOfTimesEachPhiloMustEat = ft_atoi(argv[5]);
	else
		data->numberOfTimesEachPhiloMustEat = 0;
	data->startTime = ft_get_time_of_day_in_ms();
	data->end = 0;
	data->dead = 0;
	i = 0;
	while (i < data->numberOfPhilo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->eating_locker, NULL);
	pthread_mutex_init(&data->dead_locker, NULL);
	pthread_mutex_init(&data->end_locker, NULL);
	pthread_mutex_init(&data->sasieted_locker, NULL);
}
