/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:27:08 by bbessard          #+#    #+#             */
/*   Updated: 2024/02/06 17:34:52 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead_check(t_data *rules)
{
	pthread_mutex_lock(&(rules->dead_locker));
	if (rules->dead == 1)
	{
		pthread_mutex_unlock(&(rules->dead_locker));
		return (1);
	}
	pthread_mutex_unlock(&(rules->dead_locker));
	return (0);
}

int	ft_end_check(t_data *rules)
{
	pthread_mutex_lock(&(rules->end_locker));
	if (rules->end == 1)
	{
		pthread_mutex_unlock(&(rules->end_locker));
		return (1);
	}
	pthread_mutex_unlock(&(rules->end_locker));
	return (0);
}

int	ft_sasieted_nb_check(t_data *rules)
{
	pthread_mutex_lock(&(rules->sasieted_locker));
	if (rules->number_of_satieted_philo == rules->number_of_philo)
	{
		pthread_mutex_unlock(&(rules->sasieted_locker));
		return (1);
	}
	pthread_mutex_unlock(&(rules->sasieted_locker));
	return (0);
}
