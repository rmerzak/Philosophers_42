/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:30 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/04 16:22:19 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc,char **argv) 
{
    int             fret;
    t_philosopher   *philo;
    fret = ft_check_argument(argc, argv);
    if (fret == 1)
        ft_erreur(1);
    ft_initialise(philo, argv, argc);
    return (1);
}