/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split_quote.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 13:43:48 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 18:14:07 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int ft_count_wordy(char *str)
{
	int len;
	len = 0;
	while (*str)
	{
		while (*str && *str == '"')
			str++;
		if (*str && *str != '"')
		{
			len++;
			while (*str && *str != '"')
				str++;
		}
	}
	return (len);
}

char  *ft_mallocc(char *str)
{
	char *word;
	int i;
	i = 0;
	while (str[i] && str[i] != '"')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;

	while (str[i] && str[i] != '"')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char **ft_split_quote(char *str)
{
	char **result;
	int len;
	int i;
	i = 0;

	len = ft_count_wordy(str);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	while (*str)
	{
		while (*str && *str == '"')
			str++;
		if (*str && *str != '"')
		{
			result[i] = ft_mallocc(str);
			i++;
			while (*str && *str != '"')
				str++;
		}
	}
	result[i] = NULL;
	return (result);
}
