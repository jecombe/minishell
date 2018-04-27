/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 14:39:20 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 14:05:35 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_free(char **tab, char **env, char **cmd)
{
	ft_free_tab(tab);
	ft_free_tab(env);
	ft_free_tab(cmd);
}

void		ft_free_tool(char *buff, char *cmd, t_minishell *shell)
{
	ft_strdel(&buff);
	ft_strdel(&cmd);
	ft_free_tab(shell->cmd);
}
