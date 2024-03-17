/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:43:07 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/16 14:19:17 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_charbits(int pid, char c)
{
    int i;

    i = 8;
    while(i--)
    {
        int sig;
    
        if((c >> i) & 1)
            sig = SIGUSR2;
        else
            sig = SIGUSR1;
        kill(pid, sig);
        usleep(500);
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
        i++;
    }
    send_charbits(pid, '\0');
    return (0);
}
