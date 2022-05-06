/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:52:37 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/06 14:14:39 by rmerzak          ###   ########.fr       */
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