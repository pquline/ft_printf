/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:51:27 by pfischof          #+#    #+#             */
/*   Updated: 2024/11/30 21:52:24 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *destination, char *source)
{
	int	index;

	index = 0;
	while (source != NULL && source[index] != NULL_CHAR)
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = source[index];
	return (destination);
}
