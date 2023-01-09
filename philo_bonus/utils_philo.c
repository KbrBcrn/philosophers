/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:41 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/09 12:27:13 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(int time)
{
	long	now;
	long	start;

	start = get_time();
	while (1)
	{
		now = get_time();
		if (now - start >= time)
			break ;
		usleep(100);
	}
}

void	sem_for_prints(t_table *table, char *str)
{
	int		phi;
	long	now;

	phi = table->id + 1;
	now = get_time() - table->start_time;
	sem_wait(table->sem_print);
	printf("%ld %d %s", now, phi, str);
	sem_post(table->sem_print);
}

int	ft_destroy(t_table *table)
{
	sem_close(table->sem_fork);
	sem_close(table->sem_dead);
	sem_close(table->sem_print);
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_dead");
	free (table->pid);
	return (1);
}
