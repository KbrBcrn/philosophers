/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:14:58 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/20 12:45:14 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_mutexes(t_table *table)
{
	int	index;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (0);
	index = 0;
	while (index < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[index], NULL) != 0)
			return (printf("Pthread_mutex_init() failed."));
		index++;
	}
	if (pthread_mutex_init(table->write, NULL) != 0)
		return (printf("Pthread_mutex_init() failed."));
	if (pthread_mutex_init(table->death, NULL) != 0)
		return (printf("Pthread_mutex_init() failed."));
	return (1);
}

int	ft_create_threads(t_table *table)
{
	int	i;

	i = 0;
	table->thread_id= malloc(sizeof(pthread_t) * table->nb_philo);
	if (!table->thread_id)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->thread_id[i], NULL, (void *)philo_routine,
				&(table->philo[i])) != 0)
			return (printf("Pthread_create() failed."));
		i++;
	}
	return (1);
}
