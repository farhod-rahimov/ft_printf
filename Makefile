# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btammara <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/14 11:36:07 by btammara          #+#    #+#              #
#    Updated: 2020/12/09 10:06:15 by btammara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./printf_utils/ft_16xtoa.c \
		./printf_utils/ft_atoi.c \
		./printf_utils/ft_itoa.c \
		./printf_utils/ft_printf_utils1.c \
		./printf_utils/ft_printf_utils2.c \
		./printf_utils/ft_putstr_fd.c \
		./printf_utils/ft_putstr_if_tmp_arg_null_term.c \
		./printf_utils/ft_toupper.c \
		./handlers/ft_work_with_type_c.c \
		./handlers/ft_work_with_type_diu.c \
		./handlers/part_1_diu.c \
		./handlers/part_2_diu.c \
		./handlers/part_3_diu.c \
		./handlers/ft_work_with_type_s.c \
		./handlers/part_1_s.c \
		./handlers/part_2_s.c \
		./handlers/ft_work_with_type_p.c \
		./handlers/part_1_p.c \
		./handlers/ft_work_with_type_prcnt.c \
		./handlers/ft_work_with_type_x.c \
		./handlers/part_1_x.c \
		./parser/ft_parser.c \
		./parser/part_1_parser.c \
		./parser/part_2_parser.c \
		./parser/part_3_parser.c \
		./ft_printf.c \
		./printf_utils/part_1_printf.c \

OBJS	= 	$(SRCS:.c=.o)

NAME	= 	libftprintf.a

CC		= 	gcc
RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:	
			$(CC) -c $(CFLAGS) -I libft.h $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			make clean

all:		$(NAME)

clean:		
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
