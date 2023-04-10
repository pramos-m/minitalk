/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:40:29 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/09 17:31:24 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_msg;

static void	handler(int sig, siginfo_t *data, void *NonusedData)
{
	static int	bit;
	static char	ch = '\0';

	(void) NonusedData;
	if (sig == SIGUSR1)
		ch = ch | 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		new_byte(&ch, data->si_pid);
		ch = '\0';
		bit = 0;
	}
	usleep(60);
	if (kill(data->si_pid, SIGUSR1) == -1)
		ft_error_handler(ERRCODE3);
}

void	new_byte(char *ch, int pid)
{
	char		newbyte[2];
	char		*tmp;

	newbyte[0] = *ch;
	newbyte[1] = '\0';
	if (g_msg == NULL)
		ft_strdup("");
	tmp = ft_strjoin(g_msg, ch);
	free(g_msg);
	g_msg = tmp;
	if (!g_msg)
		ft_error_handler(ERRCODE0);
	if (*ch == '\0')
	{
		ft_printf("%s", g_msg);
		if (kill(pid, SIGUSR2) == -1)
			ft_error_handler(ERRCODE3);
		g_msg = NULL;
	}
}

void	handler_error(int sig, siginfo_t *data, void *NonusedData)
{
	(void) sig;
	(void) data;
	(void) NonusedData;
	free(g_msg);
	exit(0);
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	error;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	error.sa_sigaction = handler_error;
	error.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &error, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		pause();
	}
	return (0);
}
