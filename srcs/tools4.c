/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools4.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 15:23:24 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:27:21 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int				ft_check_n(char *buff)
{
	if (buff[0] == '\n')
	{
		ft_strdel(&buff);
		return (1);
	}
	return (0);
}

int				ft_next(char *cmd, char *buff, t_minishell *shell)
{
	cmd = ft_epure(buff);
	if (cmd[0] == '/')
	{
		ft_exec_slash(cmd, shell);
		return (1);
	}
	return (0);
}

void			ft_exec_slash(char *cmd, t_minishell *shell)
{
	int t;

	t = 0;
	if (cmd[0] == '/')
	{
		g_p = 1;
		while (cmd[t] != '\n')
			t++;
		cmd[t] = '\0';
		t = 0;
		shell->cmd = ft_strsplit2(cmd);
		ft_builtin(cmd, shell);
		return ;
	}
}

void			aff_prompt_next2(char *cmd, t_minishell *shell, int t,
		char *buff)
{
	t = 0;
	(void)buff;
	cmd = ft_epure(buff);
	while (cmd[t] != '\n')
		t++;
	if (cmd[t - 1] == ' ')
		cmd[t - 1] = '\0';
	else
		cmd[t] = '\0';
	shell->cmd = ft_strsplit2(cmd);
}
