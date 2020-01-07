/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:55:57 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/06 18:14:44 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parse_conv(const char *format, int i, va_list arg, t_data *data)
{
	static void	(*conv_len[9])(va_list, t_data *) = {c_len, s_len,
		p_len, i_len, i_len, u_len, x_len, x_len, perc_len};

	i = parse_flags(format, i, data);
	if (format[i] == '*')
	{
		data->flags = turn_bit_on(data->flags, W_AST);
		data->width = va_arg(arg, int);
		if (data->width < 0)
		{
			data->flags = turn_bit_on(data->flags, MINUS);
			data->width *= -1;
		}
		i++;
	}
	else
		i = parse_len(format, i, &(data->width));
	i = parse_prec(format, arg, i, data);
	data->type = conv_index(format + i);
	if (data->type != ERROR)
		conv_len[data->type](arg, data);
	else
		i = ERROR;
	data->end = i + 1;
	return (i);
}

t_data	*parse_conv_wrapper(const char *format, int *i, va_list arg, t_data **b)
{
	t_data		*data;

	data = lstnew_data(b);
	if (data != NULL)
	{
		*i = parse_conv(format, *i + 1, arg, data);
		if (*i == ERROR)
			data = NULL;
	}
	return (data);
}

int		parse_and_get_size(const char *format, va_list arg, t_data **begin)
{
	int			len;
	int			i;
	t_data		*data;

	i = 0;
	len = 0;
	data = NULL;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			len++;
		else
		{
			data = parse_conv_wrapper(format, &i, arg, begin);
			if (data == NULL)
			{
				len = ERROR;
				break ;
			}
			len += data->len;
		}
		i++;
	}
	return (len);
}

void	fill_output(const char *format, va_list arg, t_data *data, char *output)
{
	static void	(*fill_type[9])(va_list, t_data *, char *) = {c_fill, s_fill,
		p_fill, i_fill, i_fill, u_fill, lx_fill, ux_fill, perc_fill};
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			output[j++] = format[i++];
		else
		{
			if (read_bit(data->flags, W_AST) == 1)
				va_arg(arg, int);
			if (read_bit(data->flags, P_AST) == 1)
				va_arg(arg, int);
			fill_type[data->type](arg, data, output + j);
			j += data->len;
			i = data->end;
			data = data->next;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		total_len;
	char	*output;
	t_data	*data;

	data = NULL;
	va_start(arg, format);
	total_len = parse_and_get_size(format, arg, &data);
	if (total_len != ERROR)
	{
		va_end(arg);
		va_start(arg, format);
		output = (char *)malloc(sizeof(char) * total_len);
		if (output != NULL)
		{
			fill_output(format, arg, data, output);
			write(1, output, total_len);
			free(output);
		}
	}
	free_data(data);
	va_end(arg);
	return (total_len);
}
