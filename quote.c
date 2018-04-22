/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quote.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:56:28 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/22 15:01:16 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			ft_check_quote(char *buff)
{
	int i;
	int co;

	i = 0;
	co  =0;
	while (buff[i])
	{
		if (buff[i] == 34 || buff[i] == 39)
			co++;
		i++;
	}
	return (co);
}

char		*ft_ajout_quote(char *str)
{
	int i = 0;
	int ok = 0;
	int j = 0;
	int ok2 = 0;
	char	*result;
	result =ft_strnew(4096);

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
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
	if (result[j - 1] != '"')
	{
		result[j] = '"';
		j++;
	}
	result[j] = '\0';
	return(result);

}


