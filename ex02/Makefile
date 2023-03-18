# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 02:51:43 by fstitou           #+#    #+#              #
#    Updated: 2023/03/18 02:41:56 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PmergeMe
CC		= c++ -std=c++98 
FLAGS	= -Wall -Werror -Wextra
SRCS 	= main.cpp PmergeMe.cpp

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all