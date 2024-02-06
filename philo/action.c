/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:16:53 by bat               #+#    #+#             */
/*   Updated: 2024/02/06 17:49:31 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *args)
{
	t_philo	*philo;
	t_data	*rules;

	philo = (t_philo *)args;
	rules = philo->data;
	if (rules->number_of_philo == 1)
		ft_die(rules, philo->philo_id);
	if (philo->philo_id % 2)
		usleep(1000);
	while (!ft_dead_check(rules))
	{
		ft_eat(philo);
		if (ft_end_check(rules) == 1)
			break ;
		ft_sleep(rules, philo);
		ft_think(rules, philo);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	t_data	*rules;

	rules = philo->data;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	ft_print_message(rules, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	ft_print_message(rules, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(rules->eating_locker));
	philo->last_meal = ft_get_time_of_day_in_ms();
	philo->state = EAT;
	ft_print_message(rules, philo->philo_id, ft_get_state(philo->state));
	pthread_mutex_unlock(&(rules->eating_locker));
	ft_thread_sleep(rules->time_to_eat, rules);
	philo->number_of_meal_eaten++;
	pthread_mutex_lock(&(rules->sasieted_locker));
	if (rules->number_of_times_each_philo_must_eat == \
		philo->number_of_meal_eaten)
	{
		rules->number_of_satieted_philo++;
	}
	pthread_mutex_unlock(&(rules->sasieted_locker));
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

void	ft_sleep(t_data *rules, t_philo *philo)
{
	philo->state = SLEEP;
	ft_print_message(rules, philo->philo_id, ft_get_state(philo->state));
	ft_thread_sleep(rules->time_to_sleep, rules);
}

void	ft_think(t_data *rules, t_philo *philo)
{
	philo->state = THINK;
	ft_print_message(rules, philo->philo_id, ft_get_state(philo->state));
}
