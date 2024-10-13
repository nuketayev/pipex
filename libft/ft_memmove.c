/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:43:34 by anuketay          #+#    #+#             */
/*   Updated: 2023/12/20 19:43:35 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	if (n == 0)
		return (dest);
	if (dest > src)
	{
		while (i > 0)
		{
			((char *) dest)[i] = ((char *) src)[i];
			i--;
		}
		((char *) dest)[i] = ((char *) src)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
int main(void)
{return (0);}
*/
