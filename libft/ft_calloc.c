/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anuketay <anuketay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:21:25 by anuketay          #+#    #+#             */
/*   Updated: 2023/12/17 16:42:28 by anuketay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elems, size_t elem_size)
{
	size_t	total_size;
	size_t	i;
	void	*ptr;

	total_size = num_elems * elem_size;
	if (num_elems && total_size / num_elems != elem_size)
		return (NULL);
	ptr = malloc(total_size);
	i = 0;
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (total_size-- > 0)
		{
			((char *)ptr)[i++] = 0;
		}
		return (ptr);
	}
}
