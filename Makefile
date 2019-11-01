# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 21:51:34 by ncolomer          #+#    #+#              #
#    Updated: 2019/10/27 16:36:11 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_printf.c \
					str/str_add_back.c str/str_clear.c str/str_write.c \
					str/str_iter.c str/str_last.c str/str_new.c \
					flags/flags_init.c flags/flags_new.c flags/flags_parse.c \
					transform/left_adjust.c transform/zero_pad.c transform/shrink_expand.c \
					transform/transform_value.c \
					malloc_format/malloc_int.c malloc_format/malloc_str.c \
					utils/utils_memory.c utils/utils_char.c utils/utils_str.c \
					utils/utils_int.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re