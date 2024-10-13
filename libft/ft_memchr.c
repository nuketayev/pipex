/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:22:47 by anuketay          #+#    #+#             */
/*   Updated: 2023/12/17 14:22:48 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		unc;
	const unsigned char	*src;

	src = s;
	unc = c;
	while (n > 0)
	{
		if (*src == unc)
			return ((void *)src);
		src++;
		n--;
	}
	return (NULL);
}
