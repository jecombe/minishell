/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quote.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:56:28 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 15:13:57 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int				ft_check_quote(char *buff)
{
	int i;
	int co;

	i = 0;
	co = 0;
	while (buff[i])
	{
		if (buff[i] == 34 || buff[i] == 39)
			co++;
		i++;
	}
	return (co);
}

static int		ft_check_after(char *str, int i, int ok)
{
	if (str[i + 1] == '"')
	{
		if (ft_is_prime(ok) == 1)
			i++;
		ok++;
	}
	return (ok);
}

static char		*ft_end_quote(char *result, int j)
{
	if (result[j - 1] != '"')
	{
		result[j] = '"';
		j++;
	}
	result[j] = '\0';
	return (result);
}

static char		*ft_ajout_quote_next(char *str, char *result, int ok)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '"')
		{
			if (ft_is_prime(ok) == 1)
				i++;
			ok++;
		}
		if (str[i] == ' ' && ft_is_prime(ok) == 1 && str[i + 1] != '"')
		{
			result[j] = '"';
			i++;
			j++;
		}
		result[j] = str[i];
		i++;
		j++;
	}
	result = ft_end_quote(result, j);
	return (result);
}

char			*ft_ajout_quote(char *str)
{
	int			i;
	char		*result;
	int			ok;

	i = 0;
	ok = 0;
	result = ft_strnew(4096);
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	result = ft_ajout_quote_next(str, result, ok);
	return (result);
}
