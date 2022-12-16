/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:23:45 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/15 11:53:28 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("Invalid number of arguments."));
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			return (printf("Enter only digits."));
		i++;
	}
	return (1);
}

int	init_philosophers(t_table *table)
{
	int		i;

	i = 0;
	table->philo = malloc (sizeof(t_philo) * table->nb_philo);
	if (!table->philo)
		return (0);
	while (i < table->nb_philo)
	{
		table->philo[i].nb_meal = 0;
		table->philo[i].last_meal = get_time();
		table->philo[i].id = i;
		table->philo[i].table = table;
		i++;
	}
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
	int		i;

	i = 0;
	table = malloc (sizeof(t_table));
	if (!table)
		return (0);
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->total_meals = ft_atoi(argv[5]);
	else
		table->total_meals = 0;
	if (!init_philosophers(table))
		return (0);
	table->start_time = get_time();
	return (1);
}
