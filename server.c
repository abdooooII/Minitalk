/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:37:34 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/16 20:42:10 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void server_home(void)
{
    
    
    ft_putstr_fd("\033[0;32m", 1);
    ft_putstr_fd("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n", 1);
    printf("\033[0;34m");
    ft_putchar_fd('\n', 1);
    printf("███████ ███████ ██████  ██    ██ ███████ ██████  \n");
    printf("██      ██      ██   ██ ██    ██ ██      ██   ██ \n");
    printf("███████ █████   ██████  ██    ██ █████   ██████  \n");
    printf("     ██ ██      ██   ██  ██  ██  ██      ██   ██ \n");
    printf("███████ ███████ ██   ██   ████   ███████ ██   ██ \n");
    ft_putstr_fd("\033[0;31m", 1);
    ft_putstr_fd("                  PID : ", 1);
    ft_putnbr(getpid());
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("\033[0;32m", 1);
    ft_putstr_fd("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n", 1);
    ft_putstr_fd("\033[0m", 1);
}

int main(int ac, char **av)
{
    (void)av;
    if(ac != 1)
        return(1);
    server_home();
}