/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:40 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/06 20:34:48 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_routine(t_philosopher *philo)
{
    
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
        data->philo[i].check_die_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
        if (pthread_create(&data->philo[i].threadPhiloId, NULL, ft_routine, (void*)(&philo[i]))
            return (1);
        i++;
    }    

    return (0);
}