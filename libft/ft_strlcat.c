/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:39:19 by anuketay          #+#    #+#             */
/*   Updated: 2023/12/20 19:39:28 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	j;
	size_t	slen;

	dlen = (ft_strlen(dst));
	slen = ft_strlen(src);
	j = 0;
	while (((dlen + j) < (size - 1)) && (src[j]) && size > 0)
	{
		dst[dlen + j] = src[j];
		j++;
	}
	dst[dlen + j] = 0;
	if (dlen > size)
		dlen = size;
	return (dlen + slen);
}
/*
#include <stdio.h>

int	main(void)
{
	char	p[] = "B";
	char	p2[] = "AAAAAAAAA";

	printf("return is %zu\n is sotred %s", ft_strlcat(p, p2, 0),p);
}*/
