/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_fills.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:18:35 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/04 16:18:59 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	c_fill(va_list arg, t_data *data, char *output)
{
	output = fill_width(data, output);
	output[0] = (unsigned char)va_arg(arg, int);
}

void	s_fill(va_list arg, t_data *data, char *output)
{
	char		*s;

	s = va_arg(arg, char *);
	if (s == NULL)
		s = "(null)";
	if (read_bit(data->flags, PREC) == 1 && data->arglen > data->prec)
		data->arglen = data->prec;
	output = fill_width(data, output);
	ft_memcpy(output, s, data->arglen);
}

void	perc_fill(va_list arg, t_data *data, char *output)
{
	(void)arg;
	(void)data;
	output = fill_width(data, output);
	output[0] = '%';
}
