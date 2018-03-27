/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecombe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 03:20:06 by jecombe           #+#    #+#             */
/*   Updated: 2017/11/18 18:16:06 by jecombe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int min;
	int max;
	int length;

	min = 0;
	if (!s)
		return (NULL);
	while (s[min] != '\0' && (s[min] == ' ' || s[min] == '\n'
				|| s[min] == '\t'))
		min++;
	max = ft_strlen(s);
	while (min < max && (s[max - 1] == ' ' || s[max - 1] == '\n'
				|| s[max - 1] == '\t'))
		max--;
	if (min == max)
		return (ft_strnew(1));
	length = max - min;
	return (ft_strsub(s, min, length));
}
