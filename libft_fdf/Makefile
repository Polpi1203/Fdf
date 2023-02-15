# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Noms des fichiers libft
NAME = libftcopy.a
SRC_DIR = ./srcs
OBJ_DIR = ./obj
SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# GNL

GNL_DIR = ./ft_get_next_line_copy_2/srcs/
GNL_SRC_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_utils.c get_next_line.c
GNL_OBJ_FILES = $(GNL_SRC_FILES:.c=.o)
OBJ_GNL = $(addprefix $(OBJ_DIR)/, $(GNL_OBJ_FILES))

# Printf

PRINTF_DIR = ./ft_printf_copy_2/srcs/
PRINTF_SRC_FILES = ft_convert_base.c ft_convert_long.c ft_flag_c.c ft_flag_d.c \
					ft_flag_prc.c ft_flag_s.c ft_flag_u.c ft_printf.c ft_putchar_pf.c \
					ft_putnbr_pf.c ft_putstr_pf.c ft_strlen_int.c ft_unsigned_putnbr.c 
PRINTF_OBJ_FILES = $(PRINTF_SRC_FILES:.c=.o)
OBJ_PRINTF = $(addprefix $(OBJ_DIR)/, $(PRINTF_OBJ_FILES))

# Règles de compilation
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(OBJ_PRINTF) $(OBJ_GNL) 
	ar rc $(NAME) $(OBJ) $(OBJ_PRINTF) $(OBJ_GNL) 
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
