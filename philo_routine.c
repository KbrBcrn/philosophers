/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:42:28 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/20 00:53:58 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_and_sleep(t_philo *philo)
{
	while (philo->table->someone_died == 0 && philo->table->must_eat == 0)
	{
		if (philo->table->nb_philo == 1)
			continue ;
		pthread_mutex_lock(&philo->table->forks[philo->l_fork]);
		print_philo_status(philo, philo->table->write, "has taken a fork\n");
		pthread_mutex_lock(&philo->table->forks[philo->r_fork]);
		print_philo_status(philo, philo->table->write, "has taken a fork\n");
		print_philo_status(philo, philo->table->write, "is eating\n");
		philo->last_eat = get_time();
		ft_sleep(philo->table, philo->table->time_to_eat);
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
	philo->l_fork = philo->id;
	philo->r_fork= philo->id + 1;
	if (philo->l_fork == philo->table->nb_philo - 1)
		philo->r_fork = 0;
	if (philo->id % 2 == 1)
		ft_sleep(philo->table, 50);
	if (philo->table->someone_died == 0)
		eat_and_sleep(philo);
	return (1);
}
