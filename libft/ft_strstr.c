/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecombe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:11:11 by jecombe           #+#    #+#             */
/*   Updated: 2017/11/17 03:29:16 by jecombe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t temp;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		temp = i;
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (!needle[j])
				return ((char *)&haystack[temp]);
		}
		i = temp;
		i++;
	}
	return (0);
}
