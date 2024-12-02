/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:27:40 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 10:34:16 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *string)
{
	size_t	index;

	if (string == NULL)
		return (0);
	index = 0;
	while (string[index] != NULL_CHAR)
		index++;
	return (index);
}
