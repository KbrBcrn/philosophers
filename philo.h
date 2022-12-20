/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:14:48 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/20 12:39:10 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_table	*table;
	int				last_eat;
	int				id;
	int				l_fork;
	int				r_fork;
	int				eat_count;
}	t_philo;

typedef struct s_table
{
	unsigned int	nb_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*write;
	pthread_mutex_t	*death;
	pthread_t		*thread_id;
	int				someone_died;
	int				start_time;
	int				nb_meals;
}	t_table;

// init.c
int		check_input(int argc, char **argv);
int		is_digit(char *str);
t_table	*init_table(int argc, char **argv);
int		ft_atoi(char *str);
t_philo *init_philo(t_table *table);

int	ft_create_mutexes(t_table *table);
int	ft_create_threads(t_table *table);

int	philo_routine(t_philo *philo);
void	eat_and_sleep(t_philo *philo);

long	get_time(void);
void	print_philo_status(t_philo *philo, pthread_mutex_t *mutex, char *str);
void	ft_check_philo(t_table *table);
void	ft_check_must_eat(t_table *table);
void	ft_sleep(t_table *table, int time);
int		ft_destroy(t_table *table);


# endif