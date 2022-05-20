/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:40 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/20 19:41:12 by rmerzak          ###   ########.fr       */
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
	ft_print(data, "is eating ", philo->indexOfPhilo);
	philo->check_die_time = ft_time();
	pthread_mutex_unlock(&(data->eating));
	(philo->nbEat)++;
	usleep(data->time_to_eat * 1000);
}

int	ft_take_fork(t_data *data, t_philosopher *philo)
{
	pthread_mutex_lock(&(data->forks[philo->left_Fork]));
	ft_print(data, "has taking a fork", philo->indexOfPhilo);
	pthread_mutex_lock(&(data->forks[philo->right_Fork]));
	ft_print(data, "has taking a fork", philo->indexOfPhilo);
	ft_start_eating(data, philo);
	pthread_mutex_unlock(&(data->forks[philo->left_Fork]));
	pthread_mutex_unlock(&(data->forks[philo->right_Fork]));
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
	if (data->nbrOfPhilo == 1)
	{
		ft_print(data, "has taking a fork", copy->indexOfPhilo);
		usleep(data->time_to_die * 1000);
		return (NULL);
	}
	if (copy->indexOfPhilo % 2)
		usleep(1000);
	while (!data->die)
	{
		if (ft_take_fork(data, copy))
			break ;
		ft_print(data, "sleeping ", copy->indexOfPhilo);
		usleep(data->time_to_sleep * 1000);
		ft_print(data, "thinking ", copy->indexOfPhilo);
	}
	return ((void *)0);
}

void	ft_check_eat(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (data->number_of_times_each_philosopher_must_eat > 0 && \
			i < data->nbrOfPhilo && philo[i].nbEat > data->number_of_times_each_philosopher_must_eat)
		i++;
	if (i == data->nbrOfPhilo)
		data->eat_or_not = 1;
}

void	ft_death(t_data *data, t_philosopher *philo)
{
	int	i;

	while (!data->eat_or_not)
	{
		i = 0;
		while ((i < data->nbrOfPhilo) && (!data->die))
		{
			pthread_mutex_lock(&(data->eating));
			if ((ft_time() - philo[i].check_die_time ) > data->time_to_die)
			{
				ft_print(data, "died ", i);
				data->die = 1;
			}
			pthread_mutex_unlock(&(data->eating));
			i++;
		}
		if (data->die)
			break ;
		if (data->number_of_times_each_philosopher_must_eat > 0)
			ft_check_eat(data, data->philo);
		usleep(1000);
	}
}

void	ft_end(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < data->nbrOfPhilo)
		pthread_join(philo[i++].threadPhiloId, NULL);
	i = 0;
	while (i < data->nbrOfPhilo)
		pthread_mutex_destroy(&(data->forks[i++]));
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->printing));
}

int	ft_run_philo(t_data *data, t_philosopher *philo)
{
	int	i;

	i = 0;
	data->beginning_time = ft_time();
	while (i < data->nbrOfPhilo)
	{
		data->philo[i].check_die_time = ft_time();
		if (pthread_create(&data->philo[i].threadPhiloId, NULL, ft_routine, (void *)&(philo[i])))
			printf("thread not created");
		i++;
	}
	ft_death(data, data->philo);
	ft_end(data, data->philo);
	return (0);
}
