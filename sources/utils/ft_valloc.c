/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:03:19 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 14:32:56 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_valloc(int value, size_t count, size_t size)
{
	void	*pointer;

	if (count != 0 && (count * size / count) != size)
		return (NULL);
	pointer = (void *)malloc(count * size);
	if (pointer == NULL)
		return (NULL);
	ft_memset((char *)pointer, value, count * size);
	return ((char *)pointer);
}
