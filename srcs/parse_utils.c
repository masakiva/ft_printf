/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:13:12 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/29 14:26:02 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_sbyte		conv_index(const char *format)
{
	static char	types[] = "cspdiuxX%";
	t_sbyte		index;

	index = ft_index(types, *format);
	if (index == 9)
		index = ERROR;
	return (index);
}

static int	number_len(const char *n)
{
	int		len;

	len = 0;
	while (n[len] >= '0' && n[len] <= '9')
		len++;
	return (len);
}

int			parse_flags(const char *format, int i, t_data *data)
{
	while (format[i] != '\0')
	{
		if (format[i] == '0')
			data->flags = turn_bit_on(data->flags, ZERO);
		else if (format[i] == '-')
			data->flags = turn_bit_on(data->flags, MINUS);
		else
			break ;
		i++;
	}
	return (i);
}

int			parse_len(const char *format, int i, int *len)
{
	if (format[i] >= '0' && format[i] <= '9')
		*len = ft_atoi(format + i);
	i += number_len(format + i);
	return (i);
}

int			parse_prec(const char *format, va_list arg, int i, t_data *data)
{
	if (format[i] == '.')
	{
		data->flags = turn_bit_on(data->flags, PREC);
		i++;
		if (format[i] == '*')
		{
			data->flags = turn_bit_on(data->flags, P_AST);
			data->prec = va_arg(arg, int);
			if (data->prec < 0)
			{
				data->flags = turn_bit_off(data->flags, PREC);
				data->prec = 0;
			}
			i++;
		}
		else
			i = parse_len(format, i, &(data->prec));
	}
	return (i);
}
