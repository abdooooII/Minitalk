/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:43:07 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/22 23:36:10 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_charbits(int pid, char c)
{
	int	i;
	int	sig;

	i = 8;
	while (i--)
	{
		sig = SIGUSR1;
		if ((c >> i) & 1)
			sig = SIGUSR2;
		kill(pid, sig);
		usleep(550);
	}
	usleep(200);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("INVALID\n", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid < 0)
		return (0);
	while (av[2][i])
	{
		send_charbits(pid, av[2][i]);
		i++;
	}
	send_charbits(pid, '\0');
	return (0);
}
