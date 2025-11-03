# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 14:42:17 by lpaixao-          #+#    #+#              #
#    Updated: 2025/05/23 14:42:19 by lpaixao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CPP = c++

42CPP = g++

FLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS = \
main.cpp \
PmergeMe.cpp

#NUMBERS = 3 5 9 7 4
#NUMBERS = `shuf -i 1-100000 -n 3000 | tr "\n" " "`
#NUMBERS = "-1" "2" # Núm negativo
#NUMBERS = 948951 846 15 8 42 23 4 16 42 108 7 3 5 9 # Duplicata
NUMBERS = 0

OBJS = ${SRCS:.cpp=.o}

42OBJS = $(SRCS:.cpp=.42o)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

%.42o: %.cpp
	$(42CPP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	clear

clean:
	rm -f $(OBJS) $(42OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) $(NUMBERS)

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(NUMBERS)

42re: fclean $(42OBJS)
	$(42CPP) $(FLAGS) $(42OBJS) -o $(NAME) $(NUMBERS)
	clear

42run: 42re
	./$(NAME) $(NUMBERS)

42val: 42re
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(NUMBERS)
