/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:05:41 by kbeceren          #+#    #+#             */
/*   Updated: 2023/01/09 12:28:10 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!init(&table, argc, argv))
		return (1);
	if (!ft_create_processes(&table))
		return (1);
	if (!ft_destroy(&table))
		return (1);
	return (0);
}
