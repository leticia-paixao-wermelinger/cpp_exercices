# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 18:00:56 by lpaixao-          #+#    #+#              #
#    Updated: 2024/11/07 20:05:38 by lpaixao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

CPP = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = phonebook.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	clear

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
