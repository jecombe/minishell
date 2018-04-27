/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:36 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 12:00:35 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_exec_slash(char *cmd, char *buff, t_minishell *shell)
{
	int t;

	t = 0;
	cmd = ft_epure(buff);
	if (buff[0] == '/')
	{
		g_p = 1;
		while (cmd[t] != '\0')
		{
			if (cmd[t] == ' ' && cmd[t + 1] == '\n')
				cmd[t] = '\n';
			t++;
		}
		shell->cmd = ft_str_cmd(cmd, shell);
		ft_builtin(cmd, shell);
		return ;
	}
}

void		aff_prompt_next2(char *cmd, t_minishell *shell, int t, char *buff)
{
	cmd = ft_epure(buff);
	while (cmd[t])
	{
		if (cmd[t] == ' ' && cmd[t + 1] == '\n')
			cmd[t] = '\n';
		t++;
	}
	shell->cmd = ft_str_cmd(cmd, shell);
}

int			aff_prompt_next(char *buff, char *cmd, t_minishell *shell)
{
	int co;
	int prime;
	int t;

	t = 0;
	co = ft_check_quote(buff);
	prime = ft_is_prime(co);
	if (prime != 1)
	{
		ft_strdel(&cmd);
		ft_strdel(&buff);
		return (0);
	}
	if (co > 1 && prime == 1)
	{
		ft_check_quote(buff);
		cmd = ft_epure_quote(buff);
		cmd = ft_ajout_quote(cmd);
		shell->cmd = ft_str_cmd_quote(cmd, shell);
		free(cmd);
	}
	else
		aff_prompt_next2(cmd, shell, t, buff);
	return (1);
}

void		aff_prompt(t_minishell *shell)
{
	char	*cmd;
	char	*buff;
	int		ret;

	cmd = (char *)malloc(sizeof(char) * (4096));
	buff = (char *)malloc(sizeof(char) * (4096));
	ft_print_prompt();
	if ((ret = (read(0, buff, READ_SIZE))) != -1)
	{
		if (ft_strchr(buff, (int)'/') != NULL)
			ft_exec_slash(cmd, buff, shell);
		if (ret == 0)
		{
			ft_putchar('\n');
			exit(0);
		}
		if (ft_check_space(buff) == 0)
			return ;
		if (aff_prompt_next(buff, cmd, shell) == 0)
			return ;
		if (ft_builtin(cmd, shell) == 1)
			return ;
		ft_fork(shell);
	}
}
