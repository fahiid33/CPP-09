# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 20:42:46 by fstitou           #+#    #+#              #
#    Updated: 2023/03/16 02:52:52 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RPN
CC		= c++ -std=c++98 
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