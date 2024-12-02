/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:15:51 by pfischof          #+#    #+#             */
/*   Updated: 2024/11/30 20:16:00 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *string, int character)
{
	int	index;

	index = 0;
	while (string[index] != NULL_CHAR)
	{
		if (string[index] == (char)character)
			return ((char *)&string[index]);
		++index;
	}
	if (string[index] == (char)character)
		return ((char *)&string[index]);
	return (NULL);
}
