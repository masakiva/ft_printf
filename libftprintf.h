/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:47:24 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/04 18:09:34 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define ERROR	-1

# define PREC	0
# define WIDTH	1
# define ZERO	2
# define MINUS	3
# define W_AST	4
# define P_AST	5

typedef	uint8_t		t_byte;
typedef	int8_t		t_sbyte;
typedef	struct		s_data
{
	t_sbyte			type;
	t_byte			flags;
	int				arglen;
	int				width;
	int				prec;
	int				len;
	int				end;
	struct s_data	*next;
}					t_data;

int					ft_printf(const char *format, ...);
int					parse_and_get_size(const char *format, va_list arg,
						t_data **begin);
t_data				*parse_conv_wrapper(const char *format, int *i, va_list arg,
						t_data **b);
int					parse_conv(const char *format, int i, va_list arg,
						t_data *data);
t_data				*lstnew_data(t_data **begin);
t_data				*lstlast_data(t_data *data);
void				lstadd_data_back(t_data **begin, t_data *data);
void				free_data(t_data *data);
int					parse_flags(const char *format, int i, t_data *data);
int					parse_prec(const char *format, va_list arg, int i,
						t_data *data);
int					parse_len(const char *format, int i, int *len);
int					number_len(const char *n);
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
void				fill_output(const char *format, va_list arg,
						t_data *data, char *output);
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
