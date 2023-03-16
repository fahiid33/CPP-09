# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 02:51:43 by fstitou           #+#    #+#              #
#    Updated: 2023/03/16 20:04:20 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PmergeMe
CC		= c++ -std=c++11 
FLAGS	= -Wall -Werror -Wextra
SRCS 	= main.cpp 

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all