/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:30 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/06 15:02:52 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc,char **argv) 
{
    t_philosopher   *philo = NULL;
    t_data          *data = NULL;
    
    // fret = ft_check_argument(argc, argv);
    // if (fret == 1)
    //     ft_erreur(1);
    // fret = ft_initialise(data, philo, argv, argc);
    //   if (fret == 1)
    //     ft_erreur(2);
    if (!ft_check_argument(argc, argv) && !ft_initialise(data, philo, argv, argc))
        return (0);
    return (1);
}