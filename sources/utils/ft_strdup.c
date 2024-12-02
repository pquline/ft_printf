/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 10:25:03 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 15:08:00 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *original)
{
	int		index;
	char	*dup;

	index = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(original) + sizeof(char)));
	if (dup == NULL)
		return (NULL);
	while (original != NULL && original[index] != NULL_CHAR)
	{
		dup[index] = original[index];
		++index;
	}
	dup[index] = NULL_CHAR;
	return (dup);
}
