# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 00:53:51 by fstitou           #+#    #+#              #
#    Updated: 2023/03/15 02:07:56 by fstitou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= btc
CC		= c++ -std=c++98 
FLAGS	= -Wall -Werror -Wextra
SRCS 	= main.cpp BitcoinExchange.cpp

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all