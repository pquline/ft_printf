/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:00:01 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 21:00:47 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	length;

	index = 0;
	length = ft_strlen(dst);
	if (length >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (index < dstsize - length - sizeof(char) \
		&& src != NULL && src[index] != NULL_CHAR)
	{
		dst[index + length] = src[index];
		++index;
	}
	while (index < dstsize - length)
	{
		dst[index + length] = NULL_CHAR;
		++index;
	}
	return (ft_strlen(src) + length);
}
