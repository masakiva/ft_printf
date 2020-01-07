/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:29:06 by mvidal-a          #+#    #+#             */
/*   Updated: 2020/01/04 17:53:14 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>

typedef uint8_t	t_byte;

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
int				ft_index(char *haystack, char needle);
t_byte			turn_bit_on(t_byte b, t_byte index);
t_byte			turn_bit_off(t_byte b, t_byte index);
t_byte			read_bit(t_byte b, t_byte index);

#endif
