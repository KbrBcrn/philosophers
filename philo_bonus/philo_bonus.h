/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:01:01 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/09 12:27:46 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <time.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <signal.h>

typedef struct s_table
{
	int				id;
	int				*pid;
	atomic_long		last_meal;
	atomic_int		eat_count;
	int				nb_philo;
	int				must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start_time;
	pthread_t		dead;
	sem_t			*sem_fork;
	sem_t			*sem_dead;
	sem_t			*sem_print;
}	t_table;

int			init(t_table *table, int argc, char **argv);
void		semaphore_init(t_table *table);
int			check_input(int argc, char **argv);
int			ft_create_processes(t_table *table);
void		child(t_table *table, int id);
void		eat_and_sleep(t_table *table);

void		sem_for_prints(t_table *table, char *str);
void		ft_sleep(int time);
long		get_time(void);
int			ft_exit(char *str);
int			is_digit(char *str);
int			ft_atoi(char *str);
int			ft_destroy(t_table *table);

#endif