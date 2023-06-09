/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:51:20 by pramos-m          #+#    #+#             */
/*   Updated: 2022/10/17 16:42:21 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hexa_lower(unsigned long long hexa, int count)
{
	char	*base;

	base = "0123456789abcdef";
	if (hexa > 15)
		count = ft_print_hexa_lower(hexa / 16, count);
	count = ft_print_char(base[hexa % 16], count);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_print_pointer(void *p, int count)
{
	count = ft_print_str("0x", count);
	if (count == -1)
		return (-1);
	count = ft_print_hexa_lower((unsigned long long)p, count);
	if (count == -1)
		return (-1);
	return (count);
}
