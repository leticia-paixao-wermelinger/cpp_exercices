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

NAME = serializer

CPP = c++

42CPP = g++

FLAGS = -g -Wall -Wextra -Werror -std=c++98
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html

SRCS = \
main.cpp \
ScalarConverter.cpp

OBJS = ${SRCS:.cpp=.o}

42OBJS = $(SRCS:.cpp=.42o)

#ARG = 0
#ARG = nan
ARG = 42.0f

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
	./$(NAME) $(ARG)

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARG)

42re: fclean $(42OBJS)
	$(42CPP) $(FLAGS) $(42OBJS) -o $(NAME)
	clear

42run: 42re
	./$(NAME) $(ARG)

42val: 42re
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARG)
