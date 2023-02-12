/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:27 by kbeceren          #+#    #+#             */
/*   Updated: 2023/02/11 20:16:03 by kbeceren         ###   ########.fr       */
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
# include <stdatomic.h>
# include <stdbool.h>

struct	s_table;

typedef struct s_philo
{
	int				id;
	int				state;
	atomic_long		last_meal;
	atomic_int		eat_count;
	struct s_table	*table;
	int	fork[2];
}	t_philo;

typedef struct s_table
{
	atomic_int		nb_philo;
	atomic_int		must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start_time;
	atomic_bool		are_full;
	atomic_bool		someone_died;
	t_philo			*philo;
	pthread_t		*thread_id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*write;
	pthread_mutex_t	*death;
}	t_table;

int		ft_atoi(char *str);
int		is_digit(char *str);
void	ft_sleep(t_table *table, int time);
long	get_time(void);
void	ft_check_death(t_table *table);
void	ft_check_must_eat(t_table *table);
void	print_philo_status(t_philo *philo, pthread_mutex_t *mutex, char *str);
char	error_message(char *str);

int		check_input(int argc, char **argv);
int		init_table(t_table *table, int argc, char **argv);
int		ft_create_threads(t_table *table);
int		ft_create_mutexes(t_table *table);
int		ft_destroy(t_table *table);
int		philo_routine(t_philo *philo);

#endif
