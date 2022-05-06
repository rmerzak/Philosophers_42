/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:40 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/06 20:51:20 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_routine(void *philo)
{
    (void )philo;
    printf("hello from ft_routine\n");
    return (void *)0;
}

int		ft_run_philo(t_data *data, t_philosopher *philo)
{
    int             i;
    struct timeval  time;

    i = 0;

    gettimeofday(&time, NULL);
    data->beginning_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
    while (i < data->nbrOfPhilo)
    {
        printf("%d\n",data->nbrOfPhilo);
        data->philo[i].check_die_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
        pthread_create(&data->philo[i].threadPhiloId, NULL, ft_routine, (void*)(&philo[i]));
        i++;
    }
    while (i < data->nbrOfPhilo)
    {
        pthread_join();
        i++;
    }
    return (0);
}