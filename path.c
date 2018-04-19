/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 14:41:54 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 11:51:52 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			ft_check_path(char **env)
{
	int ok;
	int compare;
	int i;

	i = 0;
	ok = 0;
	compare = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			ok = 1;
		i++;
	}
	if (ok == 0)
		ft_putendl("PATH is not set");
	return (ok);

}

int			ft_count(char *str, int value)
{
	int i;
	int co;

	co = 1;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (value == 0)
			if (str[i] == ':' && str[i + 1] != '\0')
				co++;
		if (value == 1)
			if (str[i] == ' ' && str[i + 1] != '\0')
				co++;
		i++;
	}
	return (co);
}

int			ft_count_char(char *str)
{
	int co;
	co = 0;
	while (str[co] != ' ' && str[co] != '\n' && str[co] != '\0')
		co++;
	co++;
	return (co);

}

char		**path(t_minishell *shell, char **env)
{
	int i;
	int checkPath;
	int compare;

	checkPath = ft_check_path(env);
	if (checkPath == 1)
	{
		compare = 0;
		i = 0;
		while (shell->env[i] != NULL)
		{
			if ((compare = (ft_strncmp("PATH=", shell->env[i], 5) == 0)))
			{
				return (ft_strsplit(shell->env[i], ':'));
			}
			i++;
		}

	}
	return (0);
}
