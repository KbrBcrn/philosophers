/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:22:52 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/14 16:07:45 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t		thread;
	struct t_table	*table;
	
}	t_philo;

typedef struct s_table
{
	unsigned int	nb_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	t_philo			*philo;
	int				nb_meal;
	long			start_time;
	
}	t_table;



#endif