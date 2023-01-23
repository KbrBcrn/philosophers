# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 11:10:12 by kbeceren          #+#    #+#              #
#    Updated: 2023/01/07 22:37:59 by kbeceren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c\
		utils.c\
		utils_philo.c\
		init.c\
		create_processes.c\
		philo_routine.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread

NAME = philo_bonus

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
