/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:17:30 by bat               #+#    #+#             */
/*   Updated: 2024/02/04 17:14:58 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_get_time_of_day(void)
{
	int timeInMilliseconds;
    struct timeval tv;

    gettimeofday(&tv, NULL);
	timeInMilliseconds = tv.tv_usec * 1000;

    printf("Seconds since 1/1/1970: %lu\n",tv.tv_sec);
    printf("Milliseconds since 1/1/1970: %d\n", timeInMilliseconds);

    return(0);
}