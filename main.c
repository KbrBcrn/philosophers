/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:14:13 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/20 12:45:28 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table *table;
	
	table = NULL;
	if (!check_input(argc, argv))
		return (1);
	table = init_table(argc, argv);
	if (!ft_create_mutexes(table))
		return (1);
	// if (!ft_create_threads(table))
	// 	return (1);
	// ft_check_philo(table);
	// if (!ft_destroy(table))
	// 	return (1);
	// return (0);
}
