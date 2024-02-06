/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:10:05 by bat               #+#    #+#             */
/*   Updated: 2024/02/06 17:37:25 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philosophers[i].philo_id = i + 1;
		data->philosophers[i].data = data;
		data->philosophers[i].right_fork_id = i;
		data->philosophers[i].left_fork_id = (i + 1) % data->number_of_philo;
		data->philosophers[i].number_of_meal_eaten = 0;
		data->philosophers[i].state = THINK;
		i++;
	}
}

void	ft_init_data_and_args(t_data *data, char *argv[])
{
	int	i;

	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->number_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_times_each_philo_must_eat = 0;
	data->start_time = ft_get_time_of_day_in_ms();
	data->end = 0;
	data->dead = 0;
	i = 0;
	while (i < data->number_of_philo)
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
