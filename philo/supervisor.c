/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:03:36 by bbessard          #+#    #+#             */
/*   Updated: 2024/02/06 17:38:25 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_supervisor(t_data *rules)
{
	int	i;
	int	end;
	int	time_since_last_meal;

	i = 0;
	end = 0;
	while (i < rules->number_of_philo && !ft_dead_check(rules) \
		&& !ft_end_check(rules))
	{
		time_since_last_meal = get_time_since_last_meal(rules, i);
		if (time_since_last_meal >= rules->time_to_die)
			break ;
		if (ft_sasieted_nb_check(rules) == 1)
		{
			end = 1;
			break ;
		}
		i++;
		if (i == rules->number_of_philo)
			i = 0;
	}
	check_the_issue(rules, end, i);
}

int	get_time_since_last_meal(t_data *rules, int i)
{
	int	time_since_last_meal;

	pthread_mutex_lock(&(rules->eating_locker));
	time_since_last_meal = ft_get_time_of_day_in_ms() - \
		rules->philosophers[i].last_meal;
	pthread_mutex_unlock(&(rules->eating_locker));
	return (time_since_last_meal);
}

void	check_the_issue(t_data *rules, int end, int i)
{
	if (end == 1)
		ft_end(rules);
	else
		ft_die(rules, rules->philosophers[i].philo_id);
}
