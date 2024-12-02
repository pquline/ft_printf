/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:20:04 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 10:35:56 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(char *output, const char *format, va_list ap)
{
	t_data	data;

	if (format == NULL)
		return (ERROR);
	init_data(&data);
	process_format(&data, format, ap);
	ft_strcpy(output, data.output.content);
	ft_free((void **)&data.output.content);
	return (data.output.size);
}
