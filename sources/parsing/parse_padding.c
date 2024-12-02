/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:45:09 by pfischof          #+#    #+#             */
/*   Updated: 2024/11/30 20:46:09 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_padding(t_data *data, char character)
{
	data->flags[WIDTH] = true;
	data->padding.size *= 10;
	data->padding.size += character - ZERO_CHAR;
	return (sizeof(char));
}
