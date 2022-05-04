/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:30 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/04 20:20:41 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc,char **argv) 
{
    int             fret;
    t_philosopher   *philo;
    t_data          *data;

    data = (t_data *)malloc(sizeof(t_data));
    philo = (t_philosopher *)malloc(sizeof(t_philosopher));
    fret = ft_check_argument(argc, argv);
    if (fret == 1)
        ft_erreur(1);
    fret = ft_initialise(data, philo, argv, argc);
    return (1);
}