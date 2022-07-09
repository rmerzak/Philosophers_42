/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:30 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/21 20:30:58 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	if (!data->philo)
		free(data->philo);
	if (!data->forks)
		free(data->forks);
	free(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 5 || argc == 6)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (0);
		if (ft_check_argument(argc, argv) == 1 \
				|| ft_initialise(data, argv, argc) == 1)
		{
			ft_free(data);
			printf("erreur\n");
			return (1);
		}
		ft_run_philo(data, data->philo);
		ft_free(data);
	}
	else
	{
		printf("erreur: nomber argument\n");
	}
	return (0);
}
/**/
