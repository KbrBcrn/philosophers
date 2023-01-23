/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:10:07 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/16 13:17:02 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!init_table(&table, argc, argv))
		return (1);
	if (!ft_create_mutexes(&table))
		return (1);
	if (!ft_create_threads(&table))
		return (1);
	ft_check_death(&table);
	if (!ft_destroy(&table))
		return (1);
	return (0);
}
