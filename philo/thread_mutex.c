/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:34 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/19 13:37:01 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_mutexes(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (0);
	table->death = malloc(sizeof(pthread_mutex_t));
	if (!table->death)
		return (0);
	table->write = malloc(sizeof(pthread_mutex_t));
	if (!table->write)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (error_message("Pthread_mutex_init() failed."));
		i++;
	}
	if (pthread_mutex_init(table->write, NULL) != 0)
		return (error_message("Pthread_mutex_init() failed."));
	if (pthread_mutex_init(table->death, NULL) != 0)
		return (error_message("Pthread_mutex_init() failed."));
	return (1);
}

int	ft_create_threads(t_table *table)
{
	int		i;

	i = 0;
	table->thread_id = malloc(sizeof(pthread_t) * table->nb_philo);
	if (!table->thread_id)
		return (0);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->thread_id[i], NULL, (void *)philo_routine,
				&(table->philo[i])) != 0)
			return (error_message("Pthread_create() failed."));
		i++;
	}
	return (1);
}

int	ft_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_join(table->thread_id[i], NULL) != 0) //In order to block the execution of a thread until another thread finishes
			return (error_message("Pthread_join() failed.")); // first parameter: the ID of the thread that this thread should wait for.
		i++;						  // our program’s main thread wait for each philosopher thread to finish
	}
	i = 0;
	if (pthread_mutex_destroy(table->write)
		|| pthread_mutex_destroy(table->death))
		return (error_message("Pthread_mutex_destroy() failed."));
	while (i < table->nb_philo)
	{
		if (pthread_mutex_destroy(&table->forks[i]))
			return (error_message("Pthread_mutex_destroy() failed."));
		i++;
	}
	free (table->write);
	free (table->death);
	free (table->philo);
	free (table->thread_id);
	free (table->forks);
	return (1);
}
