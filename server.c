/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 01:37:34 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/18 01:53:41 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void server_home(void)
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
    ft_putstr_fd("\033[0;32m", 1);
    ft_putstr_fd("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n", 1);
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("\033[0m", 1);
}


int main(int ac, char **av)
{
    (void)av;
	
	struct sigaction	sig;
	sig.sa_sigaction = 
	sig.sa_flags = SA_SIGINFO;
	
    if(ac != 1)
        return(1);

	siginfo_t ;
    server_home();
}