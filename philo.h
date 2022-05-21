/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:52:26 by rmerzak           #+#    #+#             */
/*   Updated: 2022/05/21 14:26:03 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	pthread_t		threadphiloid;
	int				nbrforks;
	int				left_fork;
	int				right_fork;
	int				indexofphilo;
	int				nbeat;
	long long		check_die_time;
	struct s_data	*data;
}	t_philosopher;

typedef struct s_data
{
	int				nbrofphilo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times;
	int				die;
	int				eat_or_not;
	long long		beginning_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	printing;
	t_philosopher	*philo;
}	t_data;
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_check_argument(int argc, char **argv);
void		ft_erreur(int a);
int			ft_check_digits(char *str);
int			ft_initialise(t_data *data, char **argv, int argc);
int			ft_initialise_philo(t_data *data);
int			ft_run_philo(t_data *data, t_philosopher *philo);
void		*ft_routine(void *philo);
void		ft_print(t_data *data, char *str, int indexOfPhilo);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_start_eating(t_data *data, t_philosopher *philo);
void		ft_death(t_data *data, t_philosopher *philo);
long long	ft_time(void);
void		ft_check_eat(t_data *data, t_philosopher *philo);
void		ft_end(t_data *data, t_philosopher *philo);
void		ft_free(t_data *data);

#endif 
