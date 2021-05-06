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

SRC_S	=	abs add atoi_base atoi bzero calloc div isalnum isalpha isascii \
			isdigit isinstr isprint isspace itoa_base itoa lst_read \
			lstadd_back lstadd_front lstclear lstdelone lstiter lstlast \
			lstmap lstnew lstsize memccpy memchr memcmp memcpy memmove \
			memset mod mult nbrlen_base putchar_fd putchar putendl_fd \
			putendl putnbr_fd putnbr putstr_fd putstr puttab_fd puttab \
			read_file split strcat strchr strcmp strcpy strdup strjoin \
			strlcat strlcpy strlen strmapi strncat strncmp strncpy \
			strnstr strrchr strstr strtrim sub substr tolower toupper \
			strndup

SRCS	=	$(addprefix $(DIR_S)ft_, $(addsuffix .c, $(SRC_S)))
INCLUDE	=	$(addprefix $(DIR_H), $(INC))

INC		=	libft.h

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(addprefix $(DIR_S)ft_, $(addsuffix .o, $(SRC_S)))

AR		=	ar rcs

## commande

all		:	 $(NAME)

.c.o	:	$(SRCS)
			$(CC) $(CFLAGS) -c -o $@ $<

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(AR) $@ $^

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
