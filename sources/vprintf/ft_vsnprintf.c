/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:20:04 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/04 04:58:27 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsnprintf(char *output, size_t size, const char *format, va_list ap)
{
	t_data	data;

	if (format == NULL)
		return (ERROR);
	init_data(&data);
	process_format(&data, format, ap);
	ft_strncpy(output, data.output.content, size - sizeof(char));
	output[size - sizeof(char)] = NULL_CHAR;
	ft_free((void **)&data.output.content);
	return (data.output.size);
}
