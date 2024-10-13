/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:44:25 by anuketay          #+#    #+#             */
/*   Updated: 2023/12/20 19:44:26 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	prnt;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		prnt = '-';
		write(fd, &prnt, 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		prnt = n + '0';
		write(fd, &prnt, 1);
	}
}
/*
int main (void)
{
	int    s = 256;
	int     fd = open("foo.txt", O_RDWR | O_CREAT);
	char    k[20] = {0};

	ft_putnbr_fd(s, fd);
	lseek(fd, 0, SEEK_SET);
	read(fd, k, 6);
	k[7] = 0;
	printf("this is what we have %s", k);
}*/
