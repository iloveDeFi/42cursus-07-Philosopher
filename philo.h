/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:15:28 by bat               #+#    #+#             */
/*   Updated: 2024/02/04 17:50:55 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_state
{
	THINK,
	EAT,
	SLEEP,
} t_state;

typedef struct s_data
{
	int numberOfPhilo;
	int timeToDie;
	int timeToEat;
	int timeToSleep;
} t_data;

typedef struct s_philo
{
	int philoID;
	int leftForkID;
	int rightForkID;
	int numberOfMealEaten;
	t_state state;
	t_data data;
} t_philo;

/* ACTION */


/* ERROR */


/* INIT */


/* MESSGAE */


/* PHILO */


/* STATE */


/* THREAD */


/* TIME */
int	ft_get_time_of_day_in_ms(void);

#endif