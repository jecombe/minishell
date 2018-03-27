/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 14:41:54 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 15:30:51 by jecombe     ###    #+. /#+    ###.fr     */
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
		{
			printf("--> %s", env[i]);
			ok = 1;
		}
		i++;
	}
	if (ok == 0)
	{
		ft_putendl("PATH is not set");
		exit(0);
	}
	return (ok);

}

void		path(t_minishell *shell, char **env)
{
	int i;
	int checkPath;
	int compare;
	(void)shell;

	checkPath = ft_check_path(env);
	if (checkPath == 1)
	{
		compare = 0;
		i = 0;
		while (env[i] != NULL)
		{
			if (compare = ft_strncmp("PATH=", env[i], 5) == 0)
		}

	}
	i = 0;

}

