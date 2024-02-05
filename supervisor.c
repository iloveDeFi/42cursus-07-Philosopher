/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:03:36 by bbessard          #+#    #+#             */
/*   Updated: 2024/02/05 10:23:32 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_supervisor(t_data *rules)
{
	int	i;
	int	end;
	int	timeSinceLastMeal;

	i = 0;
	end = 0;
	while (i < rules->numberOfPhilo && !ft_dead_check(rules) \
		&& !ft_end_check(rules))
	{
		timeSinceLastMeal = get_time_since_last_meal(rules, i);
		if (timeSinceLastMeal >= rules->timeToDie)
			break ;
		if (ft_sasieted_nb_check(rules) == 1)
		{
			end = 1;
			break ;
		}
		i++;
		if (i == rules->numberOfPhilo)
			i = 0;
	}
	check_the_issue(rules, end, i);
}

int	get_time_since_last_meal(t_data *rules, int i)
{
	int	timeSinceLastMeal;

	pthread_mutex_lock(&(rules->eating_locker));
	timeSinceLastMeal = ft_get_time_of_day_in_ms() - \
		rules->philosophers[i].lastMeal;
	pthread_mutex_unlock(&(rules->eating_locker));
	return (timeSinceLastMeal);
}

void	check_the_issue(t_data *rules, int end, int i)
{
	if (end == 1)
		ft_end(rules);
	else
		ft_die(rules, rules->philosophers[i].philoID);
}
