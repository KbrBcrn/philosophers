/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:20 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/21 23:49:01 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_and_sleep(t_philo *philo, int phi, int next)
{
	while (philo->table->someone_died == 0 && philo->table->are_full == 0)
	{
		if (philo->table->nb_philo == 1)
			continue ;
		pthread_mutex_lock(&philo->table->forks[phi]);
		print_philo_status(philo, philo->table->write, "has taken a fork\n");
		pthread_mutex_lock(&philo->table->forks[next]);
		print_philo_status(philo, philo->table->write, "has taken a fork\n");
		print_philo_status(philo, philo->table->write, "is eating\n");
		philo->last_meal = get_time();
		ft_sleep(philo->table, philo->table->time_to_eat);
		pthread_mutex_unlock(&philo->table->forks[phi]);
		pthread_mutex_unlock(&philo->table->forks[next]);
		philo->eat_count++;
		print_philo_status(philo, philo->table->write, "is sleeping\n");
		ft_sleep(philo->table, philo->table->time_to_sleep);
		print_philo_status(philo, philo->table->write, "is thinking\n");
	}
	return ;
}

int	philo_routine(t_philo *philo)
{
	int	phi;
	int	next;

	phi = philo->id;
	next = phi + 1;
	if (phi == philo->table->nb_philo - 1)
		next = 0;
	if (philo->id % 2 == 1)
		ft_sleep(philo->table, 50);
	if (philo->table->someone_died == 0)
		eat_and_sleep(philo, phi, next);
	return (1);
}
