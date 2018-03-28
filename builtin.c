/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 14:56:37 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 15:50:14 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		ft_cd(char *str, char **env)
{
	(void)str;
	(void)env;
}
int			ft_builtin(char *cmd, t_minishell *shell)
{
	(void)shell;
	if (ft_strcmp("exit", cmd) == 0)
		exit(0);
	else if (ft_strcmp("cd", shell->cmd[0]) == 0)
	{
		ft_cd(shell->cmd[1], shell->env);
		return(1);
	}
	else
		return (0);
}
