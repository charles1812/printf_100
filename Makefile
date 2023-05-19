# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 12:38:30 by cspreafi          #+#    #+#              #
#    Updated: 2023/04/24 18:00:23 by cspreafi         ###   ########.fr        #
#                                                                              #
# *****************************************************************************#

COMPILE = gcc
CFLAG = -Wall -Werror -Wextra
SRC = ft_*.c
MAINFILE = main.c
OUTPUT = -o tests
LIBRARY = rc libftprintf.a ft_*.o
NAME = libftprintf.a
OBJ = $(src:.c=.o)
CLEANCMD = rm -rf *.o
FCLEANCMD = rm -rf *.a


#compile all ft at once and put ion a library
$(NAME):$(OBJ)
	$(COMPILE) $(CFLAG) -c $(SRC)
	ar rcs libftprintf.a ft_*.o

all:$(NAME)

#to compile only one ft at the time
%.o:%.c
	$(COMPILE) $(CFLAG) -c $< -o $@

#clear all lib file
clean:
	$(CLEANCMD)

#clear all .o file
fclean: clean
	$(FCLEANCMD)

re: fclean all
