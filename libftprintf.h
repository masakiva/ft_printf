/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:47:24 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/29 14:31:33 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define ERROR	-1

enum e_flag
{
	PREC,
	WIDTH,
	ZERO,
	MINUS,
	W_AST,
	P_AST
};

typedef	uint8_t		t_byte;
typedef	int8_t		t_sbyte;
typedef	struct		s_data
{
	struct s_data	*next;
	int				arglen;
	int				width;
	int				prec;
	int				len;
	int				end;
	t_sbyte			type;
	t_byte			flags;
	char			pad[2];
}					t_data;
typedef void	(*t_conv)(va_list, t_data *);
typedef void	(*t_fill)(va_list, t_data *, char *);

t_data				*lstnew_data(t_data **begin);
void				lstadd_data_back(t_data **begin, t_data *data);
void				free_data(t_data *data);
int					parse_flags(const char *format, int i, t_data *data);
int					parse_prec(const char *format, va_list arg, int i,
						t_data *data);
int					parse_len(const char *format, int i, int *len);
t_sbyte				conv_index(const char *format);
void				c_len(va_list ap, t_data *data);
void				s_len(va_list ap, t_data *data);
int					s_add_flags(t_data *data);
void				p_len(va_list ap, t_data *data);
void				i_len(va_list ap, t_data *data);
void				u_len(va_list ap, t_data *data);
void				x_len(va_list ap, t_data *data);
int					n_add_flags(t_data *data, long n);
void				perc_len(va_list ap, t_data *data);
int					add_width(int width, int len);
void				c_fill(va_list arg, t_data *data, char *output);
void				s_fill(va_list arg, t_data *data, char *output);
void				p_fill(va_list arg, t_data *data, char *output);
void				ulitoacta_hex(unsigned long n, char *output, int len,
						t_data *data);
void				i_fill(va_list arg, t_data *data, char *output);
void				u_fill(va_list arg, t_data *data, char *output);
void				uitoacta(unsigned n, char *output, int len);
void				lx_fill(va_list arg, t_data *data, char *output);
void				ux_fill(va_list arg, t_data *data, char *output);
void				uitoacta_hex(unsigned n, char *output, unsigned len,
						char v);
void				perc_fill(va_list arg, t_data *data, char *output);
char				*fill_width(t_data *data, char *output);

#endif
