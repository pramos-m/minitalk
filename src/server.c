/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:40:29 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/08 17:02:30 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, receive_bin);
		signal(SIGUSR1, receive_bin);
		pause();
	}
	return (0);
}

void	bin_to_char(char *s)
{
	int		i;
	int		base;
	char	bit;
	int		control;
	int		result;

	i = 7;
	while (s[i])
	{
		base = 1;
		control = i;
		result = 0;
		while (base <= 128)
		{
			bit = s[control];
			if (bit == '1')
				result = result + base;
			base = base * 2;
			control--;
		}
		write(1, &result, 1);
		i = i + 8;
	}
}

void	receive_bin(int sig)
{
	static int	i = 0;
	static char	c[8];

	if (sig == SIGUSR1)
		c[i] = '1';
	else if (sig == SIGUSR2)
		c[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		bin_to_char(c);
	}
}
