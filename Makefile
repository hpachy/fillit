# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpachy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 15:27:16 by hpachy            #+#    #+#              #
#    Updated: 2016/11/18 15:27:21 by hpachy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
SRC = ./src/back_tracking.c ./src/binaire.c ./src/checker.c ./src/data_tab.c \
	  ./src/data_tetri.c ./src/main.c ./src/move.c ./src/print.c ./src/reader.c
NAME = fillit
HEAD = ./src
FICHIERO = ./back_tracking.o ./binaire.o ./checker.o ./data_tab.o ./data_tetri.o \
           ./main.o ./move.o ./print.o ./reader.o

all: $(NAME)

$(NAME): $(FICHIERO)
	gcc $(FLAG) -o $(NAME) $(FICHIERO) 
	
$(FICHIERO): $(SRC)
	gcc -c $(FLAG) $(SRC) -I$(HEAD)

clean :
	rm -f $(FICHIERO)

fclean :	clean
	rm -f $(NAME)

re :	fclean all
