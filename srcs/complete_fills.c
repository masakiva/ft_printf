/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_fills.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:49:27 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/04 16:23:57 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*fill_width(t_data *data, char *output)
{
	if (data->width > data->arglen)
	{
		data->width -= data->arglen;
		if (read_bit(data->flags, MINUS) == 1)
			ft_memset(output + data->arglen, ' ', data->width);
		else
		{
			if (read_bit(data->flags, ZERO) == 1)
			{
				if (data->type == 3 || data->type == 4)
					data->arglen += data->width;
				else
				{
					ft_memset(output, '0', data->width);
					output += data->width;
				}
			}
			else
			{
				ft_memset(output, ' ', data->width);
				output += data->width;
			}
		}
	}
	return (output);
}

void	uitoacta(unsigned n, char *output, int len)
{
	while (n > 0)
	{
		output[--len] = (char)(n % 10 + '0');
		n /= 10;
	}
	ft_memset(output, '0', len);
}

void	uitoacta_hex(unsigned n, char *output, unsigned len, char v)
{
	while (n > 0)
	{
		if (n % 16 > 9)
			output[--len] = (char)(n % 16 - 10 + v);
		else
			output[--len] = (char)(n % 16 + '0');
		n /= 16;
	}
	ft_memset(output, '0', len);
}

void	ulitoacta_hex(unsigned long n, char *output, int len, t_data *data)
{
	if (n == 0 && !(read_bit(data->flags, PREC) == 1 && data->prec == 0))
		output[--len] = '0';
	while (n > 0)
	{
		if (n % 16 > 9)
			output[--len] = (char)(n % 16 - 10 + 'a');
		else
			output[--len] = (char)(n % 16 + '0');
		n /= 16;
	}
}
