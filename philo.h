/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:15:28 by bat               #+#    #+#             */
/*   Updated: 2024/02/05 09:06:06 by bbessard         ###   ########.fr       */
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
	int 			numberOfPhilo;
	int 			timeToDie;
	int 			timeToEat;
	int 			timeToSleep;
	int 			numberOfTimesEachPhiloMustEat;
	int 			numberOfSatietedPhilo;
	int 			startTime;
	int 			end;
	int 			dead;
	pthread_mutex_t	dead_locker;
	pthread_mutex_t	end_locker;
	pthread_mutex_t	sasieted_locker;
	pthread_mutex_t	eating_locker;
	pthread_mutex_t	write;
	pthread_mutex_t	forks[200];
	t_philo			philosophers[200];
} t_data;

typedef struct s_philo
{
	pthread_t 		threadID;
	int 			philoID;
	int 			rightForkID;
	int 			leftForkID;
	int 			lastMeal;
	int 			numberOfMealEaten;
	long long 		deathTimer;
	t_state 		state;
	struct s_data	*data;
} t_philo;

/* ACTION */


/* ERROR */


/* INIT */
void 	ft_init_philo(t_data *data);
void 	ft_init_data_and_args(t_data *data, char *argv[]);

/* MESSAGE */


/* PHILO */


/* STATE */


/* SUPERVISOR */
void	ft_supervisor(t_data *rules);
int		get_time_since_last_meal(t_data *rules, int i);
void	check_the_issue(t_data *rules, int end, int i);

/* THREAD */


/* TIME */
int	ft_get_time_of_day_in_ms(void);

/* UTILS */
int ft_atoi(char *str);

#endif