/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:04:09 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 14:35:21 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *pointer, int character, size_t length)
{
	size_t			index;
	unsigned char	*string;

	index = 0;
	string = (unsigned char *)pointer;
	while (index < length - sizeof(char))
	{
		string[index] = (unsigned char)character;
		++index;
	}
	string[index] = NULL_CHAR;
	return (pointer);
}
