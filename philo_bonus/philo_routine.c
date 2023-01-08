/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:19:39 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/07 22:32:03 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_and_sleep(t_table *table)
{
	while (1)
	{
		sem_wait(table->sem_fork);
		sem_for_prints(table, "has taken a fork\n");
		sem_wait(table->sem_fork);
		sem_for_prints(table, "has taken a fork\n");
		sem_for_prints(table, "is eating\n");
		table->last_meal = get_time();
		ft_sleep(table->time_to_eat);
		sem_post(table->sem_fork);
		sem_post(table->sem_fork);
		table->eat_count++;
		sem_for_prints(table, "is sleeping\n");
		ft_sleep(table->time_to_sleep);
		sem_for_prints(table, "is thinking\n");
	}
}
