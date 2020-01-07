# **************************************************************************** #
#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 13:17:34 by mvidal-a          #+#    #+#              #
#    Updated: 2019/12/23 13:51:03 by mvidal-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		+= ft_atoi.c
SRCS		+= ft_memcpy.c
SRCS		+= ft_memset.c
SRCS		+= ft_strlen.c
SRCS		+= ft_index.c
SRCS		+= read_bit.c
SRCS		+= turn_bit_off.c
SRCS		+= turn_bit_on.c

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIR		= objects

NAME		= libft.a

INCLUDES	= ./

HEADER		= $(INCLUDES)libft.h

CC			= clang

CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $@ $^

$(OBJDIR)/%.o:	%.c
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJS):		$(HEADER) | $(OBJDIR)

$(OBJDIR):
				mkdir $@

clean:
				$(RM) -r $(OBJDIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
