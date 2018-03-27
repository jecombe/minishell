/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecombe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:49:18 by jecombe           #+#    #+#             */
/*   Updated: 2017/11/17 17:53:23 by jecombe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *oct1;
	unsigned char *oct2;

	if (src == dst || n == 0)
		return (dst);
	oct1 = (unsigned char*)dst;
	oct2 = (unsigned char*)src;
	while (n--)
		*oct1++ = *oct2++;
	return (dst);
}
