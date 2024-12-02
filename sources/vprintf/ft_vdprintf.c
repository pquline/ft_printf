/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:20:04 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 21:22:27 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_data	data;

	if (format == NULL)
		return (ERROR);
	init_data(&data);
	process_format(&data, format, ap);
	write(fd, data.output.content, data.output.size);
	ft_free((void **)&data.output.content);
	return (data.output.size);
}
