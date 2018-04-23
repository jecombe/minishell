/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   epure.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 15:00:01 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/22 15:00:41 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char		*ft_epure(char *str)
{
	int i;
	int j;

	if (!str)
		return(0);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			str[j] = str[i];
			j++;
			if (str[i + 1] ==  ' ' || str[i + 1] == '\t')
			{
				str[j] = ' ';
				j++;
			}
		}
	}
	str[j] = '\0';
	if (str[j - 1] == ' ')
		str[j - 1] = '\0';
	return (str);
}

char		*ft_epure_quote(char *str)
{
	int i;
	int ok;
	int ok2;
	ok2 = 0;
	char	*result;
	int j  = 0;
	ok = 0;
	i = 0;
	if (str[i] == ' ')
		while (str[i] == ' ')
			i++;
	while (str[i])
	{
		if (str[i] == '"')
			ok++;
		if (str[i] == ' ' && ft_is_prime(ok) == 1)
			while (str[i + 1] == ' ')
				i++;
		str[j] = str[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
