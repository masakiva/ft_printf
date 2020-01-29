/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_lens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:08:24 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/04 16:13:11 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	c_len(va_list arg, t_data *data)
{
	va_arg(arg, int);
	data->arglen = 1;
	data->len = add_width(data->width, 1);
}

void	s_len(va_list arg, t_data *data)
{
	char	*s;

	s = va_arg(arg, char *);
	if (s != NULL)
		data->arglen = ft_strlen(s);
	else
		data->arglen = 6;
	data->len = s_add_flags(data);
}

void	perc_len(va_list arg, t_data *data)
{
	(void)arg;
	data->arglen = 1;
	data->len = add_width(data->width, 1);
}
