/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:39:15 by pfischof          #+#    #+#             */
/*   Updated: 2024/11/30 20:44:00 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flag(t_data *data, char character)
{
	if (character == OPT_LEFT_ADJUST)
		data->flags[LEFT_ADJUSTING] = true;
	if (character == OPT_ZERO_PADDING)
		data->flags[ZERO_PADDING] = true;
	if (character == OPT_ALT_FORM)
		data->flags[ALTERNATE_FORM] = true;
	if (character == OPT_SPACE && data->flags[SIGN] == false)
		data->flags[FORCED_SPACE] = true;
	if (character == OPT_SIGNED)
		data->flags[SIGN] = true;
	return (sizeof(char));
}
