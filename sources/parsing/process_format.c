/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:33:48 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 22:08:34 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_format(t_data *data, const char *format, va_list ap)
{
	size_t	index;
	size_t	length;

	index = 0;
	length = 0;
	while (format[index] != NULL_CHAR)
	{
		clean_data(data);
		length = parse_format(data, &format[index]);
		if (length > 0)
		{
			index += length;
			convert_field(data, ap);
		}
		else
			convert_character(data, format[index]);
		join_data(data);
		index += sizeof(char);
	}
	clean_data(data);
}
