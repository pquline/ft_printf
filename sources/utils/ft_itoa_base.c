/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:47:22 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 15:52:25 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_get_len_base(unsigned long long number, int base)
{
	int	length;

	length = sizeof(char);
	while (number >= (unsigned long long)base)
	{
		++length;
		number /= base;
	}
	return (length);
}

static char	*ft_get_base(int *base_length)
{
	if (*base_length == -BASE_16)
		return (*base_length = -(*base_length), HEX_LOWER);
	if (*base_length == BASE_16)
		return (HEX_UPPER);
	return (DECIMAL);
}

char	*ft_itoa_base(unsigned long long number, int base_length)
{
	int			length;
	char		*str_number;
	const char	*base = ft_get_base(&base_length);

	length = ft_get_len_base(number, base_length);
	str_number = (char *)malloc(length + sizeof(char));
	if (str_number == NULL)
		return (NULL);
	str_number[length] = NULL_CHAR;
	if (number == 0)
		str_number[0] = ZERO_CHAR;
	while (length > 0 && number > 0)
	{
		--length;
		str_number[length] = base[number % base_length];
		number /= base_length;
	}
	return (str_number);
}
