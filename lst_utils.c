/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:14:59 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/06 18:15:07 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	free_data(t_data *data)
{
	t_data	*tmp;

	while (data != NULL)
	{
		tmp = data->next;
		free(data);
		data = tmp;
	}
}

t_data	*lstlast_data(t_data *data)
{
	while (data->next != NULL)
		data = data->next;
	return (data);
}

void	lstadd_data_back(t_data **begin, t_data *data)
{
	if (*begin == NULL)
		*begin = data;
	else
		lstlast_data(*begin)->next = data;
}

t_data	*lstnew_data(t_data **begin)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data != NULL)
	{
		data->flags = 0b00000000;
		data->width = 0;
		data->prec = 0;
		data->next = NULL;
		lstadd_data_back(begin, data);
	}
	return (data);
}
