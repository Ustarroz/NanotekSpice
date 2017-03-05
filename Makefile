##
## Makefile for bonjour in /home/voyevoda/rendu/cpp_d06/ex01
## 
## Made by voyevoda
## Login   <voyevoda@epitech.net>
## 
## Started on  Mon Jan  9 19:18:13 2017 voyevoda
## Last update Mon Mar  6 00:42:21 2017 puilla_e
##

CC	= g++

RM	= rm -f

CPPFLAGS =  -Wall -Wextra -Werror -std=c++11
CPPFLAGS += -I./include

SRC	= src/AComponent.cpp main.cpp \
	  src/Error.cpp	\
	  src/Parser.cpp \
	  src/ASubComponent.cpp \
	  src/GateOr.cpp \
	  src/GateAnd.cpp \
	  src/GateNot.cpp \
	  src/GateXor.cpp \
	  src/GateNOr.cpp \
	  src/GateNAnd.cpp \
	  src/GateNXor.cpp \
	  src/ComponentInput.cpp \
	  src/ComponentClock.cpp \
	  src/ComponentOutput.cpp \
	  src/ComponentTrue.cpp \
	  src/ComponentFalse.cpp \
	  src/Component4001.cpp \
	  src/Component4008.cpp \
	  src/Component4011.cpp \
	  src/Component4030.cpp \
	  src/Component4069.cpp \
	  src/Component4071.cpp \
	  src/Component4081.cpp	\
	  src/Circuit.cpp \
	  src/GateNull.cpp


NAME	= nanotekspice

OBJ	= $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all	: $(NAME)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
