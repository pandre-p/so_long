# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 16:34:14 by ppassos           #+#    #+#              #
#    Updated: 2024/11/07 14:40:10 by ppassos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = cc -g $(FLAGS)
RM = rm -f

CFILES = ft_printfb.c ft_putcharb_fd.c ft_ppercentage.c ft_strlenb.c ft_putstrb_fd.c \
ft_putnbr_baseb.c 

OBJECTS = $(CFILES:.c=.o)

# Regra para criar a biblioteca
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# Regra para compilar os arquivos .c em .o
%.o: %.c
	$(CC) -c $< -o $@

# Limpeza dos arquivos objeto
clean:
	$(RM) $(OBJECTS)

# Limpeza completa (objetos + biblioteca)
fclean: clean
	$(RM) $(NAME)

# Recompilar tudo
re: fclean all

# Regra padrão
all: $(NAME)
