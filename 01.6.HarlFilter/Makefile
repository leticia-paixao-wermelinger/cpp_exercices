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

NAME = harlFilter

CPP = c++

42CPP = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp  Harl.cpp

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
	./$(NAME) "I am not sure how tired I am today..."

debug: re
	./$(NAME) DEBUG

info: re
	./$(NAME) INFO

warning: re
	./$(NAME) WARNING

error: re
	./$(NAME) ERROR

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "I am not sure how tired I am today..."

valdebug: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) DEBUG

valinfo: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) INFO

valwarning: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) WARNING

valerror: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ERROR

42re: fclean $(42OBJS)
	$(42CPP) $(FLAGS) $(42OBJS) -o $(NAME)
	clear

42run: 42re
	./$(NAME)

42debug: 42re
	./$(NAME) DEBUG

42info: 42re
	./$(NAME) INFO

42warning: 42re
	./$(NAME) WARNING

42error: 42re
	./$(NAME) ERROR

42val: 42re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) "I am not sure how tired I am today..."

42valdebug: 42re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) DEBUG

42valinfo: 42re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) INFO

42valwarning: 42re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) WARNING

42valerror: 42re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ERROR