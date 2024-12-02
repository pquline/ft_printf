/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:55:08 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 21:58:25 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	revise_flags(t_data *data)
{
	if (data->flags[SIGN])
		data->flags[FORCED_SPACE] = false;
	if (data->flags[WIDTH] == false || data->padding.size == 0)
		data->flags[ZERO_PADDING] = false;
	if (data->format == FORMAT_CHARACTER)
		data->flags[ZERO_PADDING] = false;
	if (data->flags[LEFT_ADJUSTING])
		data->flags[ZERO_PADDING] = false;
	if (data->flags[PRECISION])
		data->flags[ZERO_PADDING] = false;
	if (data->format != FORMAT_DECIMAL && data->format != FORMAT_INTEGER)
		data->flags[SIGN] = false;
	if (data->format == FORMAT_STRING)
		data->flags[FORCED_SPACE] = false;
	if (data->format == FORMAT_PERCENT)
		clean_flags(data);
}

int	parse_format(t_data *data, const char *format)
{
	size_t	index;

	if (format[0] == FORMAT_PERCENT)
	{
		index = sizeof(char);
		while (ft_strchr(OPT, format[index]) != NULL)
			index += parse_flag(data, format[index]);
		while (ft_strchr(DECIMAL, format[index]) != NULL)
			index += parse_padding(data, format[index]);
		if (format[index] == OPT_PRECISION)
		{
			data->flags[PRECISION] = true;
			index += sizeof(char);
			while (ft_strchr(DECIMAL, format[index]) != NULL)
				index += parse_precision(data, format[index]);
		}
		if (ft_strchr(FORMAT, format[index]) != NULL)
		{
			data->format = format[index];
			revise_flags(data);
			return (index);
		}
	}
	return (0);
}
