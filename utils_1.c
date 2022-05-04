/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:35 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/04 20:20:32 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	sgn;
	int	res;
	int	i;

	sgn = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sgn);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		ft_check_digits(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0 )
            return (0);
        i++;
    }
    return (1);
}

int ft_check_argument(int argc, char **argv)
{
    int     i;

    i = 1;
    if (argc != 5 && argc != 6)
        return (1);
    while (argv[i] != NULL)
    {
        if (!ft_check_digits(argv[i]))
            return (1);
        i++;
    }
    return (0);
}

int ft_initialise_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(data->eating, NULL) != 0)
		return (1);
	if (pthread_mutex_init(data->printing, NULL) != 0)
		return (1);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (data->nbrOfPhilo + 1));
	if (data->forks == NULL)
		return (1);
	while (i <= data->nbrOfPhilo)
	{
		if (pthread_mutex_init(data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_initialise(t_data *data,t_philosopher *philo, char **argv, int argc)
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
	
	if (!ft_initialise_mutex(data))
		ft_erreur(2);	
}