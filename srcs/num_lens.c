/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_lens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:11:23 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/04 16:11:57 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	i_len(va_list arg, t_data *data)
{
	int			n;
	int			tmp;

	n = va_arg(arg, int);
	tmp = n;
	data->arglen = 0;
	if (tmp == -2147483648)
		tmp += 1;
	if (tmp <= 0)
	{
		(data->arglen)++;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		(data->arglen)++;
		tmp /= 10;
	}
	data->len = n_add_flags(data, n);
}

void	u_len(va_list arg, t_data *data)
{
	unsigned	n;
	unsigned	tmp;

	n = va_arg(arg, unsigned);
	tmp = n;
	data->arglen = 0;
	if (tmp == 0)
		(data->arglen)++;
	while (tmp > 0)
	{
		tmp /= 10;
		(data->arglen)++;
	}
	data->len = n_add_flags(data, n);
}

void	x_len(va_list arg, t_data *data)
{
	unsigned	n;
	unsigned	tmp;

	n = va_arg(arg, unsigned);
	tmp = n;
	data->arglen = 0;
	if (tmp == 0)
		(data->arglen)++;
	while (tmp > 0)
	{
		tmp /= 16;
		(data->arglen)++;
	}
	data->len = n_add_flags(data, n);
}

void	p_len(va_list arg, t_data *data)
{
	unsigned long	n;

	n = va_arg(arg, unsigned long);
	data->arglen = 2;
	if (n == 0 && !(read_bit(data->flags, PREC) == 1 && data->prec == 0))
		(data->arglen)++;
	while (n > 0)
	{
		n /= 16;
		(data->arglen)++;
	}
	data->len = add_width(data->width, data->arglen);
}
