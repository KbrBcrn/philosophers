/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:01 by kbeceren          #+#    #+#             */
/*   Updated: 2023/02/12 10:50:13 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (error_message("Incorrect number of arguments."));
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			return (error_message("Please only enter digits."));
		i++;
	}
	return (1);
}

int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philo)
		return (0);
	while (i < table->nb_philo)
	{
		table->philo[i].eat_count = 0;
		table->philo[i].last_meal = get_time();
		table->philo[i].id = i;
		table->philo[i].table = table;
		i++;
	}
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (!check_input(argc, argv))
		return (0);
	memset(table, 0, sizeof(t_table));
	table->nb_philo = ft_atoi(argv[1]);
	if (table->nb_philo == 0 || table->nb_philo > 200)
		return (error_message("Incorrect number of philosophers."));
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = -1;
	if (!init_philo(table))
		return (0);
	table->start_time = get_time();
	return (1);
}
