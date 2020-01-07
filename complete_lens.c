/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_lens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 19:04:39 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/04 16:16:17 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		add_width(int width, int len)
{
	return (width > len ? width : len);
}

int		s_add_flags(t_data *data)
{
	int		len;

	len = 0;
	if (read_bit(data->flags, PREC) == 1)
	{
		if (data->arglen > data->prec && data->prec > data->width)
			len = data->prec;
		else if (data->prec >= data->arglen && data->arglen > data->width)
			len = data->arglen;
		else
			len = data->width;
	}
	else
		len = add_width(data->width, data->arglen);
	return (len);
}

int		n_add_flags(t_data *data, long n)
{
	int		len;

	len = 0;
	if (read_bit(data->flags, PREC) == 1)
	{
		if (data->prec > 0)
		{
			if (n < 0)
				data->prec += 1;
			if (data->prec >= data->width && data->prec > data->arglen)
				len = data->prec;
			else if (data->width >= data->prec && data->width > data->arglen)
				len = data->width;
			else
				len = data->arglen;
		}
		else if (n == 0)
			data->arglen = 0;
	}
	if (data->prec == 0)
		len = add_width(data->width, data->arglen);
	return (len);
}
