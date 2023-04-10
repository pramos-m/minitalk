/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:40:21 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/09 17:18:30 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	pidserver;

	if (ac != 3)
		ft_error_handler(ERRCODE1);
	if (!ft_check_is_digit(av[1]))
		ft_error_handler(ERRCODE2);
	pidserver = ft_atoi(av[1]);
	if (pidserver < 100 || pidserver >= 99999)
		ft_error_handler(ERRCODE2);
	conv_bin(av[2], pidserver);
	exit(0);
	while (1)
		pause();
	return (0);
}

void	conv_bin(char *s, int pidserver)
{
	unsigned int		i;
	unsigned int		base;
	unsigned char		letra;

	i = 0;
	while (s[i])
	{
		base = 128;
		letra = s[i];
		while (base > 0)
		{
			if (letra >= base)
			{
				if (kill(pidserver, SIGUSR1) == -1)
					ft_error_handler(ERRCODE3);
				letra = letra - base;
			}
			else
				if (kill(pidserver, SIGUSR2) == -1)
					ft_error_handler(ERRCODE3);
			base = base / 2;
			usleep(100);
		}
		i++;
	}
}
