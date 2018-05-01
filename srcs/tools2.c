/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/27 13:22:06 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 17:29:18 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void			ft_set_env_tool(char **env_cmd, t_minishell *shell, int p, \
		char *tmp)
{

	if (!env_cmd[2])
	{
		tmp = ft_strdup("");
		free(shell->env[p]);
	shell->env[p] = ft_strdup(env_cmd[1]);
	ft_strcat(shell->env[p], "=");
	ft_strcat(shell->env[p], tmp);
	if (ft_strcmp(env_cmd[1], "PATH") == 0)
	{
		ft_free_tab(shell->tab);
	}
	//free(tmp);
	}
	else
	{
		char *tmpp;
		char *tmp1;
		int i = 0;
		tmpp = ft_strdup(env_cmd[2]);
	free(shell->env[p]);
	tmp1 = ft_strdup(env_cmd[1]);
	ft_strcat(tmp1, "=");
	ft_strcat(tmp1, tmpp);
	shell->env[p] = ft_strnew(4000);
	ft_strcpy(shell->env[p], tmp1);
	if (ft_strchr(shell->env[2], (int)':') == 0 && shell->tab)
	{
		shell->tab = ft_strsplit(shell->cmd[2], ':');
		while (shell->tab[i])
		{
			ft_strcat(shell->tab[i], "/");
			i++;

		}
	}
	free(tmp1);
	free(tmpp);
	}
}
