/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numerals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:32:02 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 21:49:42 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_alternate(t_data *data, char *alt)
{
	if (data->alternate != NULL)
		return ;
	if (alt != NULL)
		data->alternate = ft_strdup(alt);
	if (ft_strchr(HEX, data->format) != NULL \
			&& ft_strlen(data->conversion.content) == sizeof(char) \
			&& data->conversion.content[0] == ZERO_CHAR)
		data->flags[ALTERNATE_FORM] = false;
	else if (data->flags[ALTERNATE_FORM] && data->format == FORMAT_HEXA_LOWER)
		data->alternate = ft_strdup(ALT_LOWER);
	else if (data->flags[ALTERNATE_FORM] && data->format == FORMAT_HEXA_UPPER)
		data->alternate = ft_strdup(ALT_UPPER);
}

void	convert_decint(t_data *data, int number)
{
	const long long	n = (long long)number;

	if (n < 0)
	{
		data->conversion.signed_number = true;
		data->conversion.content = ft_itoa_base(-n, BASE_10);
	}
	else
		data->conversion.content = ft_itoa_base(n, BASE_10);
}

void	convert_hexadecimal(t_data *data, unsigned int number)
{
	if (data->format == FORMAT_HEXA_LOWER)
		data->conversion.content = ft_itoa_base(number, -BASE_16);
	else if (data->format == FORMAT_HEXA_UPPER)
		data->conversion.content = ft_itoa_base(number, BASE_16);
}

void	convert_pointer(t_data *data, void *pointer)
{
	if (pointer == NULL)
	{
		convert_string(data, OS_NULL_PTR);
		return ;
	}
	if (data->alternate == NULL)
		data->alternate = ft_strdup(ALT_LOWER);
	data->conversion.content = ft_itoa_base((uintptr_t)pointer, -BASE_16);
}

void	convert_uinteger(t_data *data, unsigned int number)
{
	data->conversion.content = ft_itoa_base(number, BASE_10);
}
