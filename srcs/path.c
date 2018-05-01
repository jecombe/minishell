/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 14:41:54 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 15:16:32 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int			ft_check_path(char **env, int value)
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
	{
		if (value == 1)
			ft_print_error("echo", ": Command not found !");
		else if (value == 0)
			ft_print_error(NULL, "PATH is not set");
	}
	return (ok);
}

char		**path(t_minishell *shell, char **env)
{
	int i;
	printf("PATH\n");
	int checkpath;
	int compare;

	checkpath = ft_check_path(env, 0);
	if (checkpath == 1)
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

char		*split_path(t_minishell *shell)
{
	int i;
	int o;
	int j;

	o = 0;
	j = 0;
	i = 5;
	while (shell->tab[0][i] != '\0')
	{
		shell->tab[0][j] = shell->tab[0][i];
		j++;
		i++;
	}
	shell->tab[0][j] = '/';
	shell->tab[0][j + 1] = '\0';
	return (shell->tab[0]);
}
