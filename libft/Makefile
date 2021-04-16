# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 17:22:08 by groubaud          #+#    #+#              #
#    Updated: 2021/04/01 17:22:08 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

DIR_S	=	./
DIR_H	=	./
DIR_LIB	=	./

SRC_S	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c \
			ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_isinstr.c ft_isspace.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strlcpy.c \
			ft_strlcat.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_strmapi.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c ft_putstr.c \
			ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
			ft_puttab_fd.c ft_puttab.c ft_read_file.c ft_lst_read.c\
			ft_nbrlen_base.c ft_atoi.c ft_itoa.c ft_abs.c ft_add.c ft_sub.c \
			ft_mod.c ft_div.c ft_mult.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
			ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c \

SRCS	=	$(addprefix $(DIR_S), $(SRC_S))
INCLUDE	=	$(addprefix $(DIR_H), $(INC))

INC		=	libft.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

LIB		=	ar rcs

## commande

all		:	$(NAME)

.c.o	:	$(SRCS)
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(LIB) $@ $^

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
