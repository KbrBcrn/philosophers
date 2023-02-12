/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:20 by kbeceren          #+#    #+#             */
/*   Updated: 2023/02/11 21:29:35 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_and_sleep(t_philo *philo)
{
	while (philo->table->someone_died == 0 && philo->table->are_full == 0)
	{
		if (philo->table->nb_philo == 1)
			continue ;
		pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
		print_philo_status(philo, philo->table->write, "has taken a fork\n");
		pthread_mutex_lock(&philo->table->forks[philo->fork[1]]);
		print_philo_status(philo, philo->table->write, "has taken a fork\n");
		print_philo_status(philo, philo->table->write, "is eating\n");
		philo->last_meal = get_time();
		ft_sleep(philo->table, philo->table->time_to_eat); //to suspend the execution of a philosopher thread for the required time to eat, sleep or think.
		pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
		pthread_mutex_unlock(&philo->table->forks[philo->fork[1]]);
		philo->eat_count++;
		print_philo_status(philo, philo->table->write, "is sleeping\n");
		ft_sleep(philo->table, philo->table->time_to_sleep);
		print_philo_status(philo, philo->table->write, "is thinking\n");
	}
	return ;
}

int	philo_routine(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = philo->id + 1;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->nb_philo;
		philo->fork[1] = philo->id;
		ft_sleep(philo->table, 50);
	}
	if (philo->table->someone_died == 0)
		eat_and_sleep(philo);
	return (1);
}
