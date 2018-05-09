/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/27 13:22:06 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:18:56 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int				ft_verif3(char *str, int value)
{
	int i;
	int ok;

	ok = -1;
	i = 0;
	while (str[i])
	{
		if (value == 1)
			if (str[i] == ':')
				ok++;
		if (value == 0)
			if (str[i] == '/')
				ok++;
		i++;
	}
	return (ok);
}

int				ft_verif4(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T' && str[3] == 'H'
			&& str[4] == '\0')
		return (1);
	else
		return (0);
}

void			ft_next_tools2(t_minishell *shell)
{
	int y;

	y = 0;
	if (g_ess == 0 && ft_strcmp(shell->cmd[1], "PATH") == 0 && shell->cmd[2])
	{
		if (ft_verif3(shell->cmd[2], 1) >= 0)
		{
			g_ess++;
			shell->tab = ft_split(shell->cmd[2]);
			while (shell->tab[y])
			{
				ft_strcat(shell->tab[y], "/");
				y++;
			}
		}
	}
}

char			**ft_set_env_tool(char **env_cmd, t_minishell *shell, int p, \
		char *tmp)
{
	int			len;
	char		*result;
	int			i;
	int			ok;

	i = 0;
	ok = 0;
	(void)env_cmd;
	(void)tmp;
	len = ft_strlen(shell->cmd[1]) + ft_strlen(tmp) + 2;
	result = (char *)malloc(sizeof(char) * len);
	if (ft_strcmp(shell->cmd[1], "PATH") == 0 && g_ess > 0)
	{
		ok = 1;
		g_ess = 0;
		ft_free_tab(shell->tab);
	}
	ft_next_tools2(shell);
	ft_strcpy(result, shell->cmd[1]);
	ft_strcat(result, "=");
	ft_strcat(result, tmp);
	free(shell->env[p]);
	shell->env[p] = result;
	return (shell->env);
}
