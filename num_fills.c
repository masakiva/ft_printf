/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_fills.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:19:16 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/04 16:23:37 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	i_fill(va_list arg, t_data *data, char *output)
{
	int			n;
	unsigned	un;

	n = va_arg(arg, int);
	if (read_bit(data->flags, PREC) == 1)
	{
		data->flags = turn_bit_off(data->flags, ZERO);
		if (data->prec > data->arglen)
			data->arglen = data->prec;
	}
	if (n < 0)
		un = (unsigned)(n * -1);
	else
		un = (unsigned)n;
	output = fill_width(data, output);
	uitoacta(un, output, data->arglen);
	if (n < 0)
		output[0] = '-';
}

void	u_fill(va_list arg, t_data *data, char *output)
{
	if (read_bit(data->flags, PREC) == 1)
	{
		data->flags = turn_bit_off(data->flags, ZERO);
		if (data->prec > data->arglen)
			data->arglen = data->prec;
	}
	output = fill_width(data, output);
	uitoacta(va_arg(arg, unsigned), output, data->arglen);
}

void	lx_fill(va_list arg, t_data *data, char *output)
{
	if (read_bit(data->flags, PREC) == 1)
	{
		data->flags = turn_bit_off(data->flags, ZERO);
		if (data->prec > data->arglen)
			data->arglen = data->prec;
	}
	output = fill_width(data, output);
	uitoacta_hex(va_arg(arg, unsigned), output, data->arglen, 'a');
}

void	ux_fill(va_list arg, t_data *data, char *output)
{
	if (read_bit(data->flags, PREC) == 1)
	{
		data->flags = turn_bit_off(data->flags, ZERO);
		if (data->prec > data->arglen)
			data->arglen = data->prec;
	}
	output = fill_width(data, output);
	uitoacta_hex(va_arg(arg, unsigned), output, data->arglen, 'A');
}

void	p_fill(va_list arg, t_data *data, char *output)
{
	output = fill_width(data, output);
	output[0] = '0';
	output[1] = 'x';
	ulitoacta_hex(va_arg(arg, unsigned long), output, data->arglen, data);
}
