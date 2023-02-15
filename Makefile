# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polpi <polpi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 09:28:26 by polpi             #+#    #+#              #
#    Updated: 2023/02/15 09:47:16 by polpi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Noms des fichiers
NAME = fdf
SRC_DIR = ./src
OBJ_DIR = ./obj
SRC_FILES = main.c read_file.c map.c draw.c utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Minilibx
MINILIBX_DIR = ./minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a
FRAMEWORKS = -framework OpenGL -framework AppKit

# Règles de compilation
all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) $(OBJ) $(LIBFT) $(MINILIBX) $(FRAMEWORKS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
