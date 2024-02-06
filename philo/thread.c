/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:26:15 by bbessard          #+#    #+#             */
/*   Updated: 2024/02/06 17:39:06 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_launch_dinner(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philosophers;
	while (i < data->number_of_philo)
	{
		pthread_create(&(philo[i].thread_id), NULL, ft_routine, &(philo[i]));
		pthread_mutex_lock(&(data->eating_locker));
		philo[i].last_meal = ft_get_time_of_day_in_ms();
		pthread_mutex_unlock(&(data->eating_locker));
		i++;
	}
	ft_supervisor(data);
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
}

void	ft_thread_sleep(long long action_time, t_data *rules)
{
	long long	current_time;

	current_time = ft_get_time_of_day_in_ms();
	while (!ft_dead_check(rules) && !ft_end_check(rules))
	{
		if (action_time <= ft_get_time_of_day_in_ms() - current_time)
			break ;
		usleep(10);
	}
}
