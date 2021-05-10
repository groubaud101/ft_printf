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

SRC_S	=	printf fill_tprintf free_tprintf \
			aff_tprintf

INC		=	./include/

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(addprefix $(DIR_S)ft_, $(addsuffix .c, $(SRC_S)))
OBJS	=	$(addprefix $(DIR_S)ft_, $(addsuffix .o, $(SRC_S)))

AR		=	ar rcs

LIB		=	-L $(DIR_L) -lft
LIB_P	=	-L $(DIR_S) -lprintf

TEST	=	-I $(INC) main.c

## commande

all		:	$(NAME)

test	:	all
			$(CC) -w $(TEST) $(LIB_P) -o exec
			@echo "\nTEST :\n"
			@./exec
			@rm -rf exec

lib		:
			make -C $(DIR_L) all
			cp $(DIR_L)libft.a $(NAME)

.c.o	:	$(SRCS)
			$(CC) -I$(INC) $(CFLAGS) -c -o $@ $<

$(NAME)	:	$(OBJS) $(INC)ft_printf.h
			$(AR) $@ $(OBJS)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

clean_l	:
			make -C $(DIR_L) clean

fclean_l:
			make -C $(DIR_L) fclean

re		:	fclean lib all

.PHONY	:	all clean fclean re
