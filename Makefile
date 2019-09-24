# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tprokysh <tprokysh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 17:42:16 by tprokysh          #+#    #+#              #
#    Updated: 2019/03/06 16:52:27 by tprokysh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INCDIR = includes/

SRC = draw.c errors.c gradient.c keyboard.c main.c mouse_events.c reader.c mlx_and_rotation.c

OBJDIR = objects

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

LIB = libft/libft.a

MLX = -I /usr/local/include -L /usr/local/lib -lmlx

INCDIR = includes

FLAGS = -Wall -Werror -Wextra -O3

FRAMEWORKS = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re cleanlib fcleanlib relib

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) $(OBJ) $(LIB) $(MLX) $(FRAMEWORKS) -o $(NAME)

$(LIB):
	make -C libft all

$(OBJDIR)/%.o: ./%.c $(INCDIR)/*.h | $(OBJDIR)
	gcc $(FLAGS) -o $@ -c $< -I $(INCDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -Rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

cleanlib:
	make -C libft clean

fcleanlib:
	make -C libft fclean

relib:
	make -C libft re
