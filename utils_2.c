/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:37 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/04 20:13:26 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_erreur(int a)
{
    if (a == 1)
        printf("Argument non valid\n");
    if (a == 2)
        printf("Thread not initialised\n");
}