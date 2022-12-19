/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:18:05 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/17 17:47:20 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_sleep_routine(t_philo *philo, int	r_fork, int	l_fork)
{
	while (philo->table->someone_died == 0 && philo->table->are_full == 0)
	{
		if (philo->table->nb_philo == 1)
			continue ;
		pthread_mutex_lock(&philo->table->fork[r_fork]);
		print_philo_status(philo, "has taken a fork\n");
		pthread_mutex_lock(&philo->table->fork[l_fork]);
		print_philo_status(philo, "has taken a fork\n");
		print_philo_status(philo, "is eating\n");
		philo->last_meal = time_now();
		ft_sleep(philo->table, philo->table->time_to_eat);
		pthread_mutex_unlock(&philo->table->fork[r_fork]);
		pthread_mutex_unlock(&philo->table->fork[l_fork]);
		philo->nb_meal++;
		print_philo_status(philo, "is sleeping\n");
		ft_sleep(philo->table, philo->table->time_to_sleep);
		print_philo_status(philo, "is thinking\n");
	}
	return ;
}

void	*philo_routine(void *arg)
{
	t_philo *philo;
	int		r_fork;
	int		l_fork;
	
	r_fork = philo->id;
	l_fork = r_fork + 1;
	if (r_fork == philo->table->nb_philo - 1)
		l_fork = 0;
	if (philo->id % 2 == 1)
		ft_sleep(philo->table, 50);
	if (philo->table->someone_died == 0)
		eat_sleep_routine(philo, r_fork, l_fork);
	return (NULL);
}
