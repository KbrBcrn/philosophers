/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:25:43 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/20 12:12:35 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (printf ("Invalid number of arguments."));
	while (i < argc)
	{
		if (!is_digit(argv[i]))
			return (printf ("Enter only digits."));
		i++;
	}
	return (1);
}

t_philo *init_philo(t_table *table)
{
	int		index;
	t_philo *philo;

	index = -1;
	philo = malloc(sizeof (t_philo) * table->nb_philo);
	if (!philo)
		return (0);
	while (++index < table->nb_philo)
	{
		philo[index].id = index + 1;
		philo[index].l_fork = index;
		philo[index].r_fork = (index + 1) % table->nb_philo;
		philo[index].table = table;
		philo[index].last_eat = 0;
		philo[index].eat_count = 0;	
	}
	return (philo);
}

t_table	*init_table(int argc, char **argv)
{
	t_table *table;
	
	table = malloc (sizeof(t_table));
	if (!table)
		return (0);
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = 0;
	if (table->nb_philo <= 0 || table->time_to_die < 0 || table->time_to_eat < 0
		|| table->time_to_sleep < 0 || table->must_eat < 0)
		return (0);
	table->philo = init_philo(table);
	if (!table->philo)
		return (0);
	table->start_time = get_time();
	return (table);
}