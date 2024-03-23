/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:37:34 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/22 23:21:14 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_home(void)
{
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("\033[0;32m", 1);
	ft_putstr_fd("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n", 1);
	ft_putstr_fd("\033[0;34m", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("███████ ███████ ██████  ██    ██ ███████ ██████  \n", 1);
	ft_putstr_fd("██      ██      ██   ██ ██    ██ ██      ██   ██ \n", 1);
	ft_putstr_fd("███████ █████   ██████  ██    ██ █████   ██████  \n", 1);
	ft_putstr_fd("     ██ ██      ██   ██  ██  ██  ██      ██   ██ \n", 1);
	ft_putstr_fd("███████ ███████ ██   ██   ████   ███████ ██   ██ \n", 1);
	ft_putstr_fd("\033[0;31m", 1);
	ft_putstr_fd("                  PID : ", 1);
	ft_putnbr(getpid());
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("\033[0;34m", 1);
	ft_putstr_fd("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n", 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("\033[0m", 1);
}

void	sig_handler(int signal, siginfo_t *pid_info, void *j)
{
	static int		bit;
	static int		pid;
	static char		c;

	(void)j;
	if (pid != pid_info->si_pid)
	{
		bit = 0;
		c = 0;
	}
	c = c << 1 | (signal - SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
	pid = pid_info->si_pid;
}

int	main(int ac, char **av)
{
	struct sigaction	sig;

	sig.sa_sigaction = sig_handler;
	sig.sa_flags = SA_SIGINFO;
	(void)av;
	if (ac != 1)
		return (1);
	if (sigaction(SIGUSR1, &sig, 0) == -1)
	{
		ft_putstr_fd("error SIGUSR1", 2);
		exit(EXIT_FAILURE);
	}
	else if (sigaction(SIGUSR2, &sig, 0))
	{
		ft_putstr_fd("error SIGUSR2", 2);
		exit(EXIT_FAILURE);
	}
	server_home();
	while (1)
		pause();
	return (0);
}
