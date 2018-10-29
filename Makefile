# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 16:24:25 by vlee              #+#    #+#              #
#    Updated: 2018/09/12 20:29:37 by vlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC = -I minilibx_macos \
	  	-I libft

LIBS = -L minilibx_macos \
	   	-L libft -lft -lmlx

FRAMEWORKS = -framework OpenGl \
			 	-framework Appkit

#FLAGS = -Wall -Werror -Wextra -g

SRC = main.c \
	  parse.c \
	  store.c \
	  environment.c \
	  rotate.c \
	  translate.c \
	  draw.c \
	  slopedraw.c \
	  color.c

OBJS = ft_*.o

all: minilibx_macos/libmlx.a $(NAME)

minilibx_macos/libmlx.a:
	cd minilibx_macos && make

$(NAME):
		make re -C libft/
		gcc $(INC) $(LIBS) $(FRAMEWORKS) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJS)
		rm -f $(NAME)

fclean:
		cd minilibx_macos && make clean
		clean
		make fclean -C libft/

re: clean all

//.PHONY: all clean fclean re
