/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:34:47 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 21:58:08 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_blank(t_data *data)
{
	if (data->blank != NULL || data->conversion.signed_number == true)
		return ;
	if (data->flags[FORCED_SPACE])
		data->blank = ft_strdup(BLANK);
}

void	convert_padding(t_data *data)
{
	char	padding;

	if (data->padding.content != NULL || data->flags[WIDTH] == false)
		return ;
	padding = NULL_CHAR;
	data->padding.size -= data->conversion.size;
	data->padding.size -= ft_strlen(data->alternate);
	data->padding.size -= ft_strlen(data->blank);
	data->padding.size -= ft_strlen(data->sign);
	if (data->flags[PRECISION] && data->precision.size > 0 \
			&& data->format != FORMAT_STRING)
		data->padding.size -= data->precision.size;
	if (data->padding.size > 0 && data->flags[ZERO_PADDING])
		padding = ZERO_CHAR;
	else if (data->padding.size > 0)
		padding = SPACE_CHAR;
	if (padding != NULL_CHAR)
		data->padding.content = ft_valloc(padding, data->padding.size \
			+ sizeof(char), sizeof(char));
}

void	convert_precision(t_data *data)
{
	if (data->precision.content != NULL)
		return ;
	if (data->flags[PRECISION])
		data->precision.size -= data->conversion.size;
	if (data->precision.size > 0)
		data->precision.content = ft_valloc(ZERO_CHAR, data->precision.size \
			+ sizeof(char), sizeof(char));
}

void	convert_sign(t_data *data)
{
	if (data->sign != NULL)
		return ;
	if (data->conversion.signed_number)
		data->sign = ft_strdup(MINUS_SIGN);
	else if (data->flags[SIGN])
		data->sign = ft_strdup(PLUS_SIGN);
}
