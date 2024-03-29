/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:15:28 by bat               #+#    #+#             */
/*   Updated: 2024/02/06 17:29:15 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
}	t_state;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				philo_id;
	int				right_fork_id;
	int				left_fork_id;
	int				last_meal;
	int				number_of_meal_eaten;
	long long		death_timer;
	t_state			state;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philo_must_eat;
	int				number_of_satieted_philo;
	int				start_time;
	int				end;
	int				dead;
	pthread_mutex_t	dead_locker;
	pthread_mutex_t	end_locker;
	pthread_mutex_t	sasieted_locker;
	pthread_mutex_t	eating_locker;
	pthread_mutex_t	write;
	pthread_mutex_t	forks[200];
	t_philo			philosophers[200];
}	t_data;

/* ACTION */
void	*ft_routine(void *args);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_data *rules, t_philo *philo);
void	ft_think(t_data *rules, t_philo *philo);

/* CHECK */
int		ft_dead_check(t_data *rules);
int		ft_end_check(t_data *rules);
int		ft_sasieted_nb_check(t_data *rules);

/* DESTROY */
void	ft_destroy_mutex(t_data *data);

/* ERROR */
int		ft_check_args(int argc, char *argv[]);
int		ft_check_digit(char *argv);

/* INIT */
void	ft_init_philo(t_data *data);
void	ft_init_data_and_args(t_data *data, char *argv[]);

/* MESSAGE */
int		ft_print_message(t_data *rules, int id, char *str);

/* PHILO */
int		main(int argc, char *argv[]);

/* STATE */
char	*ft_get_state(enum e_state state);
void	ft_die(t_data *rules, int id);
void	ft_end(t_data *rules);

/* SUPERVISOR */
void	ft_supervisor(t_data *rules);
int		get_time_since_last_meal(t_data *rules, int i);
void	check_the_issue(t_data *rules, int end, int i);

/* THREAD */
void	ft_launch_dinner(t_data *data);
void	ft_thread_sleep(long long action_time, t_data *rules);

/* TIME */
int		ft_get_time_of_day_in_ms(void);

/* UTILS */
int		ft_atoi(char *str);

#endif