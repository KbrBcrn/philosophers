/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:20 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/16 13:05:51 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_and_sleep(t_philo *philo)
{
	while (philo->table->someone_died == 0 && philo->table->are_full == 0)
	{
		if (philo->table->nb_philo == 1)
			continue ;
		pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
		print_philo_status(philo, philo->table->write, "has taken a fork\n");
		pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
		print_philo_status(philo, philo->table->write, "has taken a fork\n");
		print_philo_status(philo, philo->table->write, "is eating\n");
		philo->last_meal = get_time();
		ft_sleep(philo->table, philo->table->time_to_eat); //to suspend the execution of a philosopher thread for the required time to eat, sleep or think.
		pthread_mutex_unlock(&philo->table->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->table->forks[philo->r_fork]);
		philo->eat_count++;
		print_philo_status(philo, philo->table->write, "is sleeping\n");
		ft_sleep(philo->table, philo->table->time_to_sleep);
		print_philo_status(philo, philo->table->write, "is thinking\n");
	}
	return ;
}

int	philo_routine(t_philo *philo)
{
	if (philo->l_fork == philo->table->nb_philo - 1)
		philo->r_fork = 0;
	if (philo->id % 2 == 1)
		ft_sleep(philo->table, 50);
	if (philo->table->someone_died == 0)
		eat_and_sleep(philo);
	return (1);
}
