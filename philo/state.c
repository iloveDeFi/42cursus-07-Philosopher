/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:16:08 by bat               #+#    #+#             */
/*   Updated: 2024/02/05 11:24:10 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_get_state(enum e_state state)
{
	if (state == THINK)
		return ("is thinking");
	else if (state == SLEEP)
		return ("is sleeping");
	else if (state == EAT)
		return ("is eating");
	return ("");
}

void	ft_die(t_data *rules, int id)
{
	ft_print_message(rules, id, "died");
	pthread_mutex_lock(&(rules->dead_locker));
	rules->dead = 1;
	pthread_mutex_unlock(&(rules->dead_locker));
}

void	ft_end(t_data *rules)
{
	pthread_mutex_lock(&(rules->end_locker));
	rules->end = 1;
	pthread_mutex_unlock(&(rules->end_locker));
}
