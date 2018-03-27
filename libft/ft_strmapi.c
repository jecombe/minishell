/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecombe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:51:13 by jecombe           #+#    #+#             */
/*   Updated: 2017/11/16 14:43:09 by jecombe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ptr = ft_strnew(ft_strlen(s))))
		return (NULL);
	if (s && f)
	{
		while (s[i] != '\0')
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
