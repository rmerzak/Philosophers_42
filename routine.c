/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:40 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/21 14:31:03 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_data *data, char *str, int indexOfPhilo)
{
	pthread_mutex_lock(&(data->printing));
	if (!data->die)
	{
		ft_putnbr_fd(ft_time() - data->beginning_time, 1);
		ft_putchar_fd('\t', 1);
		ft_putnbr_fd((indexOfPhilo + 1), 1);
		ft_putchar_fd('\t', 1);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
	}
	pthread_mutex_unlock(&(data->printing));
}

void	ft_start_eating(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&(data->eating));
	ft_print(data, "is eating ", philo->indexofphilo);
	philo->check_die_time = ft_time();
	pthread_mutex_unlock(&(data->eating));
	(philo->nbeat)++;
	usleep(data->time_to_eat * 1000);
}

int	ft_take_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	ft_print(data, "has taking a fork", philo->indexofphilo);
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	ft_print(data, "has taking a fork", philo->indexofphilo);
	ft_start_eating(data, philo);
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
	if (data->eat_or_not)
		return (1);
	return (0);
}

void	*ft_routine(void *philo)
{
	t_philosopher	*copy;
	t_data			*data;

	copy = (t_philosopher *)philo;
	data = copy->data;
	if (data->nbrofphilo == 1)
	{
		ft_print(data, "has taking a fork", copy->indexofphilo);
		usleep(data->time_to_die * 1000);
		return (NULL);
	}
	if (copy->indexofphilo % 2)
		usleep(1000);
	while (!data->die)
	{
		if (ft_take_fork(data, copy))
			break ;
		ft_print(data, "sleeping ", copy->indexofphilo);
		usleep(data->time_to_sleep * 1000);
		ft_print(data, "thinking ", copy->indexofphilo);
	}
	return ((void *)0);
}
