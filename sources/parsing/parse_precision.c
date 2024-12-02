/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:48:34 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 16:17:48 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_precision(t_data *data, char character)
{
	data->precision.size *= 10;
	data->precision.size += character - ZERO_CHAR;
	return (sizeof(char));
}
