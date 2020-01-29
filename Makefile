# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 13:17:34 by mvidal-a          #+#    #+#              #
#    Updated: 2020/01/29 14:12:23 by mvidal-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		+= ft_printf.c
SRCS		+= parse_utils.c
SRCS		+= lst_utils.c
SRCS		+= char_lens.c
SRCS		+= num_lens.c
SRCS		+= complete_lens.c
SRCS		+= char_fills.c
SRCS		+= num_fills.c
SRCS		+= complete_fills.c

SRCS		+= ft_atoi.c
SRCS		+= ft_memcpy.c
SRCS		+= ft_memset.c
SRCS		+= ft_strlen.c
SRCS		+= ft_index.c
SRCS		+= read_bit.c
SRCS		+= turn_bit_off.c
SRCS		+= turn_bit_on.c

VPATH		= srcs:libft_srcs

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIR		= objects

NAME		= libftprintf.a

INCLUDES	= ./

HEADERS		+= $(INCLUDES)libftprintf.h
HEADERS		+= $(INCLUDES)libft.h

CC			= clang

CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror
CFLAGS		+= -Wpadded

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $@ $^

$(OBJDIR)/%.o:	%.c
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJS):		$(HEADERS) | $(OBJDIR)

$(OBJDIR):
				mkdir $@

clean:
				$(RM) -r $(OBJDIR)

fclean:			clean
				$(RM) $(NAME)


re:				fclean all

.PHONY:			all clean fclean re
