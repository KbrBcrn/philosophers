/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:18:05 by kbeceren          #+#    #+#             */
/*   Updated: 2022/12/15 13:48:27 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*philo_routine(void *arg)
{
	int		phi;
	int		next;
	t_philo *philo;
	
	phi = philo->id;
	next = phi + 1;
	if (phi == philo->table->nb_philo - 1)
		next = 0;
	if (philo->id % 2 == 1)
		ft_sleep(philo->table, 50);
	if (philo->table->someone_died == 0)
		eat_and_sleep(philo, phi, next);
	return (NULL);
}