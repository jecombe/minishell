/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/27 13:22:06 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 13:24:36 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void			ft_set_env_tool(char **env_cmd, t_minishell *shell, int p, \
		char *tmp)
{
	if (!env_cmd[2])
		env_cmd[2] = ft_strdup("");
	else
		tmp = ft_strdup(env_cmd[2]);
	free(shell->env[p]);
	shell->env[p] = ft_strdup(env_cmd[1]);
	ft_strcat(shell->env[p], "=");
	ft_strcat(shell->env[p], env_cmd[2]);
}
