# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polpi <polpi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 09:28:26 by polpi             #+#    #+#              #
#    Updated: 2023/02/15 08:32:57 by polpi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Libft
LIBFT_DIR = ./libft_fdf/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)
LIBFT_LNK = -L $(LIBFT_DIR) -lft

# Minilibx
MLX_DIR = ./minilibx_macos/
MLX = $(MLX_DIR)libmlx.a
MLX_INC = -I $(MLX_DIR)
MLX_LNK = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Sources
SRC_DIR = ./src/
SRC_FILES = main.c parse.c render.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

# Objects
OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LNK) $(MLX_LNK) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

