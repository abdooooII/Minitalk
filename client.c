/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:43:07 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/18 23:13:38 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_charbits(int pid, char c)
{
	int	i;
	int	sig;

	i = 7;
	while (i >= 0)
	{
		sig = SIGUSR1;
		if ((c >> i) & 1)
			sig = SIGUSR2;
		kill(pid, sig);
		usleep(500);
		i--;
	}
}

int main(int ac, char **av)
{
    int     i;
    int     pid;
    
    if (ac != 3)
    {
        ft_putstr_fd("INVALID\n", 2);
        exit(EXIT_FAILURE);
    }
    i = 0;
    pid = ft_atoi(av[2]);
    if(pid < 0)
        return(0);
    while(av[2])
    {
        send_charbits(pid, av[2][i]);
		printf("JJJJJJ\n");
        i++;
    }
    send_charbits(pid, '\0');
    return (0);
}
