/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:05:48 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 16:07:54 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_data(t_data *data)
{
	clean_flags(data);
	ft_free((void **)&data->alternate);
	ft_free((void **)&data->blank);
	ft_free((void **)&data->sign);
	ft_free((void **)&data->conversion.content);
	data->conversion.size = 0;
	data->conversion.signed_number = false;
	ft_free((void **)&data->padding.content);
	data->padding.size = 0;
	ft_free((void **)&data->precision.content);
	data->precision.size = 0;
	data->format = 0;
}

void	clean_flags(t_data *data)
{
	size_t	index;

	index = 0;
	while (index < NUMBER_OF_FLAGS)
	{
		data->flags[index] = false;
		++index;
	}
}
