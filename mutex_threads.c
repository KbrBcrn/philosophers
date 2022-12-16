/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:03:15 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/15 13:41:20 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_mutexes(t_table *table)
{
	int	i;
	
	i = 0;
	table->fork = malloc((sizeof(pthread_mutex_t)) * table->nb_philo);
	if (!table->fork)
		return (0);
	table->fork = malloc(sizeof(pthread_mutex_t));
	if (!table->death)
		return (0);
	table->status = malloc(sizeof(pthread_mutex_t));
	if (!table->status)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return (printf("Pthread_mutex_init() failed."));
		i++;
	}
	if (pthread_mutex_init(table->status, NULL) != 0)
		return (printf("Pthread_mutex_init() failed."));
	if (pthread_mutex_init(table->death, NULL) != 0)
		return (printf("Pthread_mutex_init() failed."));
	return (1);
}

int	ft_create_threads(t_table *table)
{
	int	i;
	
	i = 0;
	table->threads = malloc(sizeof(pthread_t) * table->nb_philo);
	if (!table->threads)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->threads[i], NULL, philo_routine, &(table->philo[i])) != 0)
				return (printf ("Pthread_create() failed."));
		i++;
	}
	return (1);
}
