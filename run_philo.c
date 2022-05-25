/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:08:13 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/22 21:05:04 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_check_eat(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (data->number_of_times > 0 \
			&& i < data->nbrofphilo && philo[i].nbeat >= data->number_of_times)
		i++;
	if (i == data->nbrofphilo)
		data->eat_or_not = 1;
}

void	ft_death(t_data *data, t_philosopher *philo)
{
	int	i;

	while (!data->eat_or_not)
	{
		i = 0;
		while ((i < data->nbrofphilo) && (!data->die))
		{
			pthread_mutex_lock(&(data->eating));
			if ((ft_time() - philo[i].check_die_time) > data->time_to_die)
			{
				ft_print(data, "died ", i);
				data->die = 1;
			}
			pthread_mutex_unlock(&(data->eating));
			i++;
		}
		if (data->die)
			break ;
		if (data->number_of_times > 0)
			ft_check_eat(data, data->philo);
		usleep(100);
	}
}

void	ft_end(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < data->nbrofphilo)
		pthread_join(philo[i++].threadphiloid, NULL);
	i = 0;
	while (i < data->nbrofphilo)
		pthread_mutex_destroy(&(data->forks[i++]));
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->printing));
}

int	ft_run_philo(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	data->beginning_time = ft_time();
	while (i < data->nbrofphilo)
	{
		data->philo[i].check_die_time = ft_time();
		if (pthread_create(&data->philo[i].threadphiloid, NULL, \
					ft_routine, (void *)&(philo[i])))
			printf("thread not created");
		i++;
	}
	ft_death(data, data->philo);
	ft_end(data, data->philo);
	return (0);
}
