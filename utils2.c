/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:27:36 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/17 21:01:59 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_table *table, int time)
{
	long	now;
	long	start;

	start = get_time();
	while (table->someone_died == 0)
	{
		now = time_now();
		if (now - start >= time)
			break ;
		usleep(100);
	}
}

void	print_philo_status(t_philo *philo, char *status)
{
}

void	check_philos_death(t_table *table)
{
	
}