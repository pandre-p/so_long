MAKEFLAGS = -s

SRCS            = main.c map_utils.c get_next_line.c get_next_line_utils.c map_checker.c \
				map_images.c open_map.c flood_fill.c map_utils2.c key_utils.c \

OBJS            = $(SRCS:.c=.o)

CC              = cc
RM              = rm -f
CFLAGS          = -g -Wall -Wextra -Werror

LIB_DIR         = ./Lib_ft
LIB_LIB         = $(LIB_DIR)/libft.a

PRINTF_DIR	=./Lib_ft/printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

mlx_DIR		= ./minilibx-linux
mlx_LIB		= $(mlx_DIR)/libmlx.a
mlx_FLAGS	= -L$(mlx_DIR) -lmlx -lXext -lX11 -lXrender -lXft -lm -lz

NAME		= so_long

# Regra principal
all: $(NAME)

# Compilação do so_long
$(NAME): $(OBJS) $(LIB_LIB) $(mlx_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_LIB) $(mlx_LIB) $(PRINTF_LIB) $(mlx_FLAGS) -o $(NAME)

# Compilar a biblioteca Lib_ft
$(LIB_LIB):
	make -C $(LIB_DIR)

# Compilar a biblioteca printf
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

# Compilar a biblioteca mlx
$(mlx_LIB):
	make -C $(mlx_DIR)

# Limpeza dos arquivos objeto
clean:
	$(RM) $(OBJS)
	make -C $(LIB_DIR) clean

# Limpeza completa
fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_DIR) fclean
	make -C $(mlx_DIR) clean
	make -C $(PRINTF_DIR) clean

# Recompilar tudo
re: fclean all
