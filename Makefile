##
## Makefile for bonjour in /home/voyevoda/rendu/cpp_d06/ex01
## 
## Made by voyevoda
## Login   <voyevoda@epitech.net>
## 
## Started on  Mon Jan  9 19:18:13 2017 voyevoda
## Last update Tue Jan 31 12:24:41 2017 voyevoda
##

CC	= g++

SRC	= ./main.cpp

CPPFLAG =  -Wall -Wextra -Werror -std=c++03

RM	= rm -f

NAME	= nanotekspice

OBJ	= $(SRC:.cpp=.o)


all	: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean	:
	$(RM) $(OBJ) $(OBJ2)

fclean	: clean
	$(RM) $(NAME) $(NAME2)

re	: fclean all

.phony	: all clean fclean re

