# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 13:17:34 by mvidal-a          #+#    #+#              #
#    Updated: 2020/01/06 18:19:41 by mvidal-a         ###   ########.fr        #
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

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIR		= objects

NAME		= libftprintf.a

INCLUDES	= ./

HEADER		= $(INCLUDES)libftprintf.h

CC			= clang

CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C libft
				cp libft/libft.a $@
				ar rcs $@ $^
				
$(OBJDIR)/%.o:	%.c
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJS):		$(HEADER) | $(OBJDIR)

$(OBJDIR):
				mkdir $@

clean:
				make fclean -C libft
				$(RM) -r $(OBJDIR)

fclean:			clean
				$(RM) $(NAME)


re:				fclean all

.PHONY:			all clean fclean re
