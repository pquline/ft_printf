/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:08:43 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/02 18:07:21 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	copy_content(char *destination, const char *source, size_t size)
{
	size_t	index;

	if (source == NULL)
		return ;
	index = 0;
	while (index < size)
	{
		if (source != NULL && source[index] != NULL_CHAR)
			destination[index] = source[index];
		else
			destination[index] = NULL_CHAR;
		++index;
	}
}

static void	join(t_data *data, const char *string, const size_t size)
{
	char	*joined;

	if (size == 0)
		return ;
	joined = ft_valloc(NULL_CHAR, data->output.size + size + sizeof(char), \
		sizeof(char));
	if (joined == NULL)
		return ;
	if (data->output.content)
		copy_content(joined, data->output.content, data->output.size);
	copy_content(joined + data->output.size, string, size);
	ft_free((void **)&data->output.content);
	data->output.content = joined;
	data->output.size += size;
}

static void	join_padding(t_data *data)
{
	data->flags[WIDTH] = false;
	if (data->flags[ZERO_PADDING] \
			&& (data->flags[SIGN] || data->conversion.signed_number))
		join(data, data->sign, sizeof(char));
	join(data, data->padding.content, ft_strlen(data->padding.content));
}

void	join_data(t_data *data)
{
	if (data->flags[WIDTH] && data->flags[LEFT_ADJUSTING] == false \
			&& ((ft_strchr(HEX, data->format) != NULL \
			|| data->flags[ALTERNATE_FORM] == false) \
			&& data->flags[ZERO_PADDING] == false))
		join_padding(data);
	if (data->flags[ZERO_PADDING] == false)
		if (data->flags[SIGN] || data->conversion.signed_number)
			join(data, data->sign, sizeof(char));
	if (data->flags[FORCED_SPACE] && data->conversion.signed_number == false)
		join(data, data->blank, sizeof(char));
	if (data->flags[ALTERNATE_FORM] || data->format == FORMAT_POINTER)
		join(data, data->alternate, ft_strlen(data->alternate));
	if (data->flags[WIDTH] && data->flags[LEFT_ADJUSTING] == false)
		join_padding(data);
	if (data->flags[PRECISION] && data->format != FORMAT_STRING \
			&& data->format != FORMAT_CHARACTER)
		join(data, data->precision.content, ft_strlen(data->precision.content));
	join(data, data->conversion.content, data->conversion.size);
	if (data->flags[WIDTH] && data->flags[LEFT_ADJUSTING])
		join(data, data->padding.content, ft_strlen(data->padding.content));
}
