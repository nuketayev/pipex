/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:46:35 by anuketay          #+#    #+#             */
/*   Updated: 2023/12/20 19:46:38 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
 int	main (void)
 {
	char *s1 = "test\0";
	char *s2 = "test\200";

printf("result is %d\nresult is %d\n ", ft_strncmp(s1,s2,6), strncmp(s1,s2,6));
 }*/
