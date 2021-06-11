# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 12:21:57 by groubaud          #+#    #+#              #
#    Updated: 2021/06/11 23:24:07 by groubaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

DIR_S	=	./ft_printf/
DIR_L	=	./libft/

SLIB	=	abs add atoi_base atoi bzero calloc div isalnum isalpha isascii \
			isdigit isinstr isprint isspace itoa_base itoa lst_read \
			lstadd_back lstadd_front lstclear lstdelone lstiter lstlast \
			lstmap lstnew lstsize memccpy memchr memcmp memcpy memmove \
			memset mod mult nbrlen_base putchar_fd putchar putendl_fd \
			putendl putnbr_fd putnbr putstr_fd putstr puttab_fd puttab \
			read_file split strcat strchr strcmp strcpy strdup strjoin \
			strlcat strlcpy strlen strmapi strncat strncmp strncpy \
			strnstr strrchr strstr strtrim sub substr tolower toupper \
			strndup putnstr putnstr_fd u_itoa_base u_ltoa_base \
			u_lltoa_base put_int put_uint put_ulong put_ulonglong the_max \
			the_min put_uchar

SPRINTF	=	printf fill_tprintf conversion_csp conversion_diuxx aff

INC		=	./include/
H_INC	=	libft ft_colors ft_printf
INCLUDE	=	$(addprefix $(INC), $(addsuffix .h, $(H_INC)))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(addprefix $(DIR_S)ft_, $(addsuffix .c, $(SPRINTF))) \
			$(addprefix $(DIR_L)ft_, $(addsuffix .c, $(SLIB)))

OBJS	=	$(addprefix $(DIR_S)ft_, $(addsuffix .o, $(SPRINTF))) \
			$(addprefix $(DIR_L)ft_, $(addsuffix .o, $(SLIB)))

AR		=	ar rcs

LIB_P	=	-L . -lftprintf
TEST	=	-I $(INC) main.c

## commande

all		:	$(NAME)

test	:	all
			$(CC) -w $(TEST) $(LIB_P) -o exec
			@echo "\nTEST :\n"
			@./exec
			@rm -rf exec

.c.o	:	$(SRCS)
			$(CC) -I$(INC) $(CFLAGS) -c -o $@ $<

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(AR) $@ $(OBJS)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
