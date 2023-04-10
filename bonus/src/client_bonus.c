/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:40:21 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/09 16:41:54 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	confirm(int sig)
{
	static long long	count = -1;

	(void)sig;
	if (sig == SIGUSR1)
	{
		++count;
		usleep(80);
		ft_printf("\r -> Received bit [%d]\r", count);
	}
	if (sig == SIGUSR2)
	{
		usleep(80);
		ft_printf(" -> Bites printed: [%d]\n", count);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int	pidserver;
	int	i;

	i = 0;
	if (ac != 3)
		ft_error_handler(ERRCODE1);
	signal(SIGUSR1, &confirm);
	signal(SIGUSR2, &confirm);
	if (!ft_check_is_digit(av[1]))
		ft_error_handler(ERRCODE2);
	pidserver = ft_atoi(av[1]);
	if (pidserver < 100 || pidserver >= 99999)
		ft_error_handler(ERRCODE2);
	while (av[2][i])
	{
		conv_bin_bonus(av[2][i], pidserver);
		i++;
	}
	conv_bin_bonus('\0', pidserver);
	while (1)
		pause();
	return (0);
}

void	conv_bin_bonus(unsigned char s, int pidserver)
{
	unsigned int		base;
	int					signal;

	base = 128;
	while (base > 0)
	{
		if (s >= base)
		{
			signal = SIGUSR1;
			s = s - base;
		}
		else
			signal = SIGUSR2;
		if (kill(pidserver, signal) == -1)
			ft_error_handler(ERRCODE3);
		pause();
		base = base / 2;
	}
}
