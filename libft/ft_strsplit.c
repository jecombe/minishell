/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecombe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:12:26 by jecombe           #+#    #+#             */
/*   Updated: 2017/11/18 19:07:02 by jecombe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		i;
	int		nbword;
	size_t	length;

	if (!s)
		return (NULL);
	i = 0;
	nbword = ft_count_word(s, c);
	if (!(dest = ((char **)malloc(sizeof(*dest) * (nbword + 1)))))
		return (NULL);
	while (nbword--)
	{
		while (*s != '\0' && *s == c)
			s++;
		length = ft_strlen_split(s, c);
		dest[i] = ft_strsub(s, 0, length);
		if (dest[i] == '\0')
			return (NULL);
		s = s + ft_strlen_split(s, c);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
