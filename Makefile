##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

SRC			=		Main.cpp

OBJ			=		$(SRC:.cpp=.o)

NAME		=		pong

all			:		$(NAME)

$(NAME)		:		$(OBJ)
					g++ -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-system -lsfml-window

clean		:
					rm -rf $(OBJ)

fclean		:		clean
					rm -rf $(NAME)

re		:			fclean all
