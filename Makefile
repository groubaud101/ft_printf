# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 12:21:57 by groubaud          #+#    #+#              #
#    Updated: 2021/04/29 12:21:57 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libprintf.a

DIR_S	=	./
DIR_L	=	./libft/

SRC_S	=	main ft_printf

INC		=	$(DIR_L)libft.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(addprefix $(DIR_S), $(addsuffix .c, $(SRC_S)))
OBJS	=	$(addprefix $(DIR_S), $(addsuffix .o, $(SRC_S)))

AR		=	ar rcs

LIB		=	-L $(DIR_L) -lft
LIB_P	=	-L $(DIR_S) -lprintf

## commande

test	:	all
			$(CC) $(CFLAGS) $(LIB_P) -o exec
			./exec

all		:	lib $(NAME)

lib		:
			make -C $(DIR_L) all
			cp $(DIR_L)libft.a $(NAME)

.c.o	:	$(SRCS)
			$(CC) -I$(DIR_L) -I. $(CFLAGS) -c -o $@ $<

$(NAME)	:	$(OBJS) $(INC)
			$(AR) $@ $^

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)
			rm -rf exec

clean_l	:
			make -C $(DIR_L) clean

fclean_l:
			make -C $(DIR_L) fclean

re		:	fclean all

.PHONY	:	all clean fclean re
