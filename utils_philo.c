/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:41 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/21 11:17:08 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_philo_status(t_philo *philo, pthread_mutex_t *mutex, char *str)
{
	int		phi;
	long	now;

	phi = philo->id + 1;
	now = get_time() - philo->table->start_time;
	pthread_mutex_lock(mutex);
	if (philo->table->someone_died == 0 && philo->table->must_eat == 0)
		printf("%ld %d %s", now, phi, str);
	pthread_mutex_unlock(mutex);
}

void	ft_check_philo(t_table *table)
{
	int		i;
	long	now;

	while (table->someone_died == 0 && table->must_eat == 0)
	{
		usleep(100);
		i = 0;
		while (i < table->nb_philo)
		{
			now = get_time();
			if (now >= table->philo[i].last_meal + table->time_to_die)
			{
				pthread_mutex_lock(table->death);
				pthread_mutex_lock(table->write);
				table->someone_died = 1;
				printf("%ld %d %s", now - table->start_time, i + 1, "died\n");
				pthread_mutex_unlock(table->write);
				pthread_mutex_unlock(table->death);
				break ;
			}
			i++;
		}
		if (table->total_meals != -1)
			ft_check_must_eat(table);
	}
}

void	ft_check_must_eat(t_table *table)
{
	int	i;

	i = 0;
	if (table->total_meals == 0)
		table->must_eat = 1;
	while (i < table->nb_philo)
	{
		if (table->philo[i].nb_meals < table->total_meals)
			break ;
		i++;
	}
	if (i == table->nb_philo)
		table->must_eat = 1;
}

void	ft_sleep(t_table *table, int time)
{
	long	now;
	long	start;

	start = get_time();
	while (table->someone_died == 0)
	{
		now = get_time();
		if (now - start >= time)
			break ;
		usleep(100);
	}
}
