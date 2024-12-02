/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_literals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:30:04 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 20:15:57 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_string(t_data *data, char *string)
{
	if (string == NULL && data->format == FORMAT_STRING \
			&& (data->flags[PRECISION] == false \
			|| data->precision.size >= ft_strlen(NULL_STR)))
		data->conversion.content = ft_strdup(NULL_STR);
	if (data->conversion.content == NULL)
		data->conversion.content = ft_strdup(string);
	data->conversion.size = ft_strlen(data->conversion.content);
}

void	convert_character(t_data *data, char character)
{
	data->conversion.content = (char *)malloc(sizeof(character) + sizeof(char));
	if (data->conversion.content == NULL)
		return ;
	data->conversion.content[0] = character;
	data->conversion.content[1] = NULL_CHAR;
	data->conversion.size = sizeof(char);
}
