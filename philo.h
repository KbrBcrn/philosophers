/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:22:52 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/17 21:02:10 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <stdlib.h>

# define FREE 0
# define LOCK 1

typedef struct s_philo
{
	struct s_table	*table;
	int				nb_meal;
	int				last_meal;
	int				id;
}	t_philo;

typedef struct s_table
{
	unsigned int	nb_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	t_philo			*philo;
	int				total_meals;
	pthread_t		*threads;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*death;
	pthread_mutex_t *status;
	long			start_time;
	int				someone_died;
	int				are_full;
}	t_table;

int		check_input(int argc, char **argv);
int		init_philosophers(t_table *table);
int		init_table(t_table *table, int argc, char **argv);
time_t	get_time(void);
int		ft_atoi(char *str);
int		is_digit(char *str);
void	*philo_routine(void *arg);
int		ft_create_threads(t_table *table);
int		ft_create_mutexes(t_table *table);
void	ft_sleep(t_table *table, int time);
void	check_philos_death(t_table *table);

#endif