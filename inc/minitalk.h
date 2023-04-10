/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:40:24 by pramos-m          #+#    #+#             */
/*   Updated: 2023/02/02 16:37:28 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <sys/types.h>
# include <stdlib.h>
# include <libft.h>
# include <ft_printf.h>

// Error Codes
# define ERRCODE0	(int)0
# define ERRCODE1	(int)1
# define ERRCODE2	(int)2
# define ERRCODE3	(int)3

// Error Messages
# define ERR_MSG0	(char *)"Error!\n"
# define ERR_MSG1	(char *)"Error! Invalid parameters given!\n"
# define ERR_MSG2	(char *)"Error! Invalid PID!\n"
# define ERR_MSG3	(char *)"Error! Signal error!\n"

//Minitalk
void	conv_bin(char *s, int pidserver);
void	receive_bin(int sig);
void	bin_to_char(char *s);
void	confirm(int sig);

//utils
int		ft_check_is_digit(char *str);
void	ft_error_handler(int error);

#endif