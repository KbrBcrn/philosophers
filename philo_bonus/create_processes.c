/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:12:35 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/09 12:04:38 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	is_dead(t_table *table)
{
	int	i;

	while (1)
	{
		usleep(1000);
		i = 0;
		while (i < table->nb_philo)
		{
			if (table->must_eat != -1
				&& table->eat_count == table->must_eat)
				exit (0);
			sem_wait(table->sem_dead);
			if (get_time() >= table->last_meal + table->time_to_die)
			{
				sem_wait(table->sem_print);
				printf("%ld %d %s", get_time() - table->start_time,
					table->id + 1, "died\n");
				exit (1);
				sem_post(table->sem_print);
			}
			sem_post(table->sem_dead);
			i++;
		}
	}
}

void	child(t_table *table, int id)
{
	if (table->id % 2 == 1)
		ft_sleep(50);
	table->id = id;
	table->last_meal = get_time();
	pthread_create(&table->dead, NULL, (void *)is_dead, table);
	eat_and_sleep(table);
}

static void	parent(t_table *table)
{
	int		i;
	int		j;
	int		status;

	i = 0;
	while (i < table->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			j = 0;
			while (j < table->nb_philo)
			{
				kill(table->pid[j], SIGKILL);
				j++;
			}
		}
		i++;
	}
}

int	ft_create_processes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		table->pid[i] = fork();
		if (table->pid[i] < 0)
			ft_exit("Fork() failed.");
		else if (table->pid[i] == 0)
		{
			table->id = i;
			break ;
		}
		i++;
	}
	if (table->pid[table->id] == 0)
		child(table, table->id);
	else
		parent(table);
	return (1);
}
