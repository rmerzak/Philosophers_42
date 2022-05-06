/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:30 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/06 18:28:37 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc,char **argv) 
{
    t_data          *data;
    
    data = (t_data *)malloc(sizeof(t_data));
    if (ft_check_argument(argc, argv) == 1 || ft_initialise(data, argv, argc) == 1)
        return (0);
	ft_run_philo(data)
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // int i = 0;
	// while(i < data->nbrOfPhilo)
	// {
	// 	printf(
	// 		"%d %d %d %d %lld\n",
	// 	data->philo[i].indexOfPhilo,
	// 	data->philo[i].left_Fork,
	// 	data->philo[i].right_Fork,
	// 	data->philo[i].nbEat,
	// 	data->philo[i].check_die_time
	// 	);
	// 	i++;
		
	// }
    return (1);
}