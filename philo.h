/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:52:26 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/06 15:05:00 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>




typedef struct s_philosopher
{
	pthread_t	threadPhiloId;
	int			nbrForks;
	int			left_Fork;
	int			right_Fork;
	int			indexOfPhilo;
	int			nbEat;
	long long	check_die_time;
	struct s_data		*data;
} t_philosopher;

typedef struct s_data
{
	int				nbrOfPhilo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				die;
	int				eat_or_not;
	long long		beginning_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	printing;
	t_philosopher	*philo;
} t_data;
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_check_argument(int argc, char **argv);
void	ft_erreur(int a);
int		ft_check_digits(char *str);
int		ft_initialise(t_data *data, t_philosopher *philo, char **argv, int argc);
int		ft_initialise_philo(t_data *data);

#endif 
