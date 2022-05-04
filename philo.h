/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:52:26 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/04 16:22:07 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>



typedef struct s_data
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
} t_data;

typedef struct s_philosopher
{
	pthread_t	philo;
	int			nbrforks;
	int			indexOfPhilo;
	t_data		data;
} t_philosopher;

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_check_argument(int argc, char **argv);
void	ft_erreur(int a);
int		ft_check_digits(char *str);
void	ft_initialise(t_philosopher philo, char **argv, int argc);


#endif 
