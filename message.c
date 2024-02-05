/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:59:26 by bbessard          #+#    #+#             */
/*   Updated: 2024/02/05 10:20:40 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_message(t_data *rules, int id, char *str)
{
	pthread_mutex_lock(&(rules->write));
	if (!ft_dead_check(rules) && !ft_end_check(rules))
	{
		printf("%d %d %s\n", ft_get_time_of_day_in_ms() - rules->startTime, id, str);
	}
	pthread_mutex_unlock(&(rules->write));
	return (0);
}