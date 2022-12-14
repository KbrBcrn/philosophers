/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:22:47 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/14 16:09:42 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!check_input(argc, argv))
		return (-1);
	if (!init_table(table, argc, argv))
	{
		free_table(table);
		return (-1);
	}
}
