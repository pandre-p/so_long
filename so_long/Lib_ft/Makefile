# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppassos <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 11:04:00 by ppassos           #+#    #+#              #
#    Updated: 2024/05/15 11:05:23 by ppassos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

CC = cc -g $(FLAGS)

CFILES = ft_isalpha.c ft_toupper.c ft_isdigit.c ft_tolower.c ft_isalnum.c \
	ft_strchr.c ft_isascii.c ft_isprint.c ft_strrchr.c ft_strlen.c \
	ft_strncmp.c ft_memset.c ft_memchr.c ft_bzero.c ft_memcpy.c \
	ft_memcmp.c ft_memmove.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c  ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

RM = rm -rf

OBJECTS = $(CFILES:.c=.o)

OBJECTS_2 = $(BONUS:.c=.o)
	
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS_2) $(NAME)
	ar rcs $(NAME) $(OBJECTS_2)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS) $(OBJECTS_2)
	
all: $(NAME)

re: fclean all

exec:
	$(CC) $(FLAGS) $(CFILES) $(BONUS) -lbsd
