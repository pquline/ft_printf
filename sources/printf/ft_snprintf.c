/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:34:27 by pfischof          #+#    #+#             */
/*   Updated: 2024/11/30 20:14:06 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_snprintf(char *output, size_t size, const char *format, ...)
{
	int		length;
	va_list	ap;

	va_start(ap, format);
	length = ft_vsnprintf(output, size, format, ap);
	va_end(ap);
	return (length);
}