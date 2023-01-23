/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:14:54 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/19 13:41:15 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (printf("Incorrect number of arguments."));
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			return (printf("Please only enter digits."));
		i++;
	}
}

void	semaphore_init(t_table *table)
{
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_dead");
	table->sem_fork = sem_open("sem_fork", O_CREAT | O_EXCL, 0644,
			table->nb_philo);
	table->sem_print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	table->sem_dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644, 1);
	if (table->sem_fork == SEM_FAILED || table->sem_print == SEM_FAILED
		|| table->sem_dead == SEM_FAILED)
		ft_exit("Sem_open() failed");
}

int	init(t_table *table, int argc, char **argv)
{
	int	i;

	i = 0;
	check_input(argc, argv);
	memset(table, 0, sizeof(t_table));
	table->nb_philo = ft_atoi(argv[1]);
	if (table->nb_philo == 0 || table->nb_philo > 200)
		return (ft_exit("Incorrect number of philosophers."));
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = -1;
	table->pid = malloc(sizeof(int) * table->nb_philo);
	if (!table->pid)
		exit(EXIT_FAILURE);
	while (i < table->nb_philo)
	{
		table->pid[i] = 0;
		i++;
	}
	semaphore_init(table);
	table->start_time = get_time();
	return (1);
}
