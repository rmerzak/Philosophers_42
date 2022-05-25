/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:35 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/22 21:23:17 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_initialise_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(data->eating), NULL))
		return (1);
	if (pthread_mutex_init(&(data->printing), NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->nbrofphilo));
	if (data->forks == NULL)
		return (1);
	while (i < data->nbrofphilo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_initialise_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_data) * data->nbrofphilo);
	if (data->philo == NULL)
		return (1);
	while (i < data->nbrofphilo)
	{
		data->philo[i].indexofphilo = i;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->nbrofphilo;
		data->philo[i].nbeat = 0;
		data->philo[i].check_die_time = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

static int	ft_check_positive(t_data *data)
{
	if (data->nbrofphilo <= 0 || data->time_to_die <= 0 \
			|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (1);
	return (0);
}

int	ft_initialise(t_data *data, char **argv, int argc)
{
	data->nbrofphilo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->number_of_times = ft_atoi(argv[5]);
		if (data->number_of_times == 0)
			return (1);
	}
	data->die = 0;
	data->eat_or_not = 0;
	data->beginning_time = 0;
	if (ft_check_positive(data))
		return (1);
	if (ft_initialise_mutex(data) || ft_initialise_philo(data))
		return (1);
	return (0);
}
