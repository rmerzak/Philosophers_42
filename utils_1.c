/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:35 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/20 17:11:44 by rmerzak          ###   ########.fr       */
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
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->nbrOfPhilo));
	if (data->forks == NULL)
		return (1);
	while (i < data->nbrOfPhilo)
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
	data->philo = malloc(sizeof(t_data) * data->nbrOfPhilo);
	if (data->philo == NULL)
		return (1);
	while (i < data->nbrOfPhilo)
	{
		data->philo[i].indexOfPhilo = i;
		data->philo[i].left_Fork = i;
		data->philo[i].right_Fork = (i + 1) % data->nbrOfPhilo;
		data->philo[i].nbEat = 0;
		data->philo[i].check_die_time = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	ft_initialise(t_data *data, char **argv, int argc)
{
	data->nbrOfPhilo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	data->die = 0;
	data->eat_or_not = 0;
	data->beginning_time = 0;
	if (ft_initialise_mutex(data) || ft_initialise_philo(data))
		return (1);
	return (0);
}
