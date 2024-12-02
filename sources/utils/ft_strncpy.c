/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:51:27 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 10:35:06 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncpy(char *destination, char *source, size_t size)
{
	size_t	index;

	index = 0;
	while (source != NULL && source[index] != NULL_CHAR && index < size)
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = source[index];
	return (destination);
}
