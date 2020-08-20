# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 09:19:15 by simoulin          #+#    #+#              #
#    Updated: 2019/08/21 15:28:04 by simoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
WALL = -Wall -Wextra -Werror
INCLUDE = includes
SRC = fct/fct_calcul.c fct/fct.c fct/othrs_fct.c main/main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
		$(CC) -I $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
		$(CC) -I $(INCLUDE) -o $(NAME) $(SRC)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME) zzz

re : fclean all
