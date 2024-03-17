/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:27:15 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/15 06:33:09 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
void    ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putstr_fd("-2147483648", 1);
    }
    else if (nb < 0)
    {
        nb = -nb;
        ft_putchar_fd('-', 1);
        ft_putnbr(nb);
    }
    else if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);   
    }
    else if (nb <= 9)
        ft_putchar_fd(nb + 48, 1);

}

int     ft_atoi(char *str)
{
    int i;
    int nb;
    int sign;

    i = 0;
    nb = 0;
    sign = 1;
    while(str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    return (nb * sign);
}
