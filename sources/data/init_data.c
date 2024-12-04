/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:35:29 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/04 04:52:56 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_data(t_data *data)
{
	clean_flags(data);
	data->format = 0;
	data->alternate = NULL;
	data->blank = NULL;
	data->sign = NULL;
	data->conversion.content = NULL;
	data->conversion.size = 0;
	data->conversion.signed_number = false;
	data->padding.content = NULL;
	data->padding.size = 0;
	data->precision.content = NULL;
	data->precision.size = 0;
	data->output.content = NULL;
	data->output.size = 0;
}
