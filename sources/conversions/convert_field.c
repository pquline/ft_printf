/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:51:24 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 20:17:57 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_format(t_data *data, va_list ap)
{
	if (data->format == FORMAT_CHARACTER)
		convert_character(data, va_arg(ap, int));
	else if (data->format == FORMAT_PERCENT)
		convert_character(data, FORMAT_PERCENT);
	else if (data->format == FORMAT_STRING)
		convert_string(data, va_arg(ap, char *));
	else if (data->format == FORMAT_POINTER)
		convert_pointer(data, va_arg(ap, void *));
	else if (data->format == FORMAT_DECIMAL || data->format == FORMAT_INTEGER)
		convert_decint(data, va_arg(ap, int));
	else if (data->format == FORMAT_UINTEGER)
		convert_uinteger(data, va_arg(ap, unsigned int));
	else if (data->format == FORMAT_HEXA_LOWER \
			|| data->format == FORMAT_HEXA_UPPER)
		convert_hexadecimal(data, va_arg(ap, unsigned int));
	if (data->format != FORMAT_CHARACTER)
		data->conversion.size = ft_strlen(data->conversion.content);
}

static void	revise_string(t_data *data)
{
	if (data->format != FORMAT_STRING || data->flags[PRECISION] == false)
		return ;
	data->conversion.size = ft_strlen(data->conversion.content);
	if (data->conversion.content && data->precision.size == 0)
		data->conversion.content[0] = NULL_CHAR;
	else if (data->precision.size < data->conversion.size)
		data->conversion.content[data->precision.size] = NULL_CHAR;
	data->conversion.size = ft_strlen(data->conversion.content);
}

static void	revise_numeric(t_data *data)
{
	if (ft_strchr(NUMERICALS, data->format) == NULL \
			|| data->flags[PRECISION] == false)
		return ;
	if (data->conversion.content && data->conversion.content[0] == ZERO_CHAR \
		&& data->conversion.content[1] == NULL_CHAR)
	{
		data->conversion.content[0] = NULL_CHAR;
		data->conversion.size = 0;
	}
}

void	convert_field(t_data *data, va_list ap)
{
	convert_format(data, ap);
	revise_string(data);
	revise_numeric(data);
	convert_alternate(data, NULL);
	convert_sign(data);
	convert_blank(data);
	convert_precision(data);
	convert_padding(data);
}
