/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:36 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 16:35:43 by jecombe     ###    #+. /#+    ###.fr     */
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
		while (cmd[t])
	{
		if (cmd[t] == ' ' && cmd[t + 1] == '\n')
			cmd[t] = '\n';
		t++;
	}
	t = 0;
	while (cmd[t] != '\n')
		t++;
	cmd[t] = '\0';
	//shell->cmd = ft_str_cmd(cmd, shell);
	shell->cmd = ft_strsplit(cmd, ' ');

		ft_builtin(cmd, shell);
		return ;
	}
}

void		aff_prompt_next2(char *cmd, t_minishell *shell, int t, char *buff)
{
	cmd = ft_epure(buff);
	t = 0;
	while (cmd[t] != '\n')
		t++;
	cmd[t] = '\0';
	//shell->cmd = ft_str_cmd(cmd, shell);
	shell->cmd = ft_strsplit(cmd, ' ');
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
		return (0);
	}
	if (co > 1 && prime == 1)
	{
		ft_check_quote(buff);
		cmd = ft_epure_quote(buff);
		cmd = ft_ajout_quote(cmd);
		shell->cmd = ft_str_cmd_quote(cmd, shell);
	}
	else
		aff_prompt_next2(cmd, shell, t, buff);
	return (1);
}

void		ft_ret_o(int ret, t_minishell *shell, char *cmd, char *buff)
{
	(void)shell;
	if (ret != 0)
	{
		return;
	}
	if (ret == 0)
	{
		ft_putchar('\n');
		//ft_putchar('\r');
		ft_free_tab(shell->env);
		ft_free_tab(shell->tab);
		if (shell->cmd)
			ft_free_tab(shell->cmd);
		ft_strdel(&g_user);
		ft_strdel(&cmd);
		ft_strdel(&buff);

		exit(0);
	}
}


int 		ft_verif(char **tab)
{
	int i;

	i = 0;
	if (tab[i] == NULL)
		return (0);
	return (1);
}
void		aff_prompt(t_minishell *shell)
{
	//char	cmd[4096];
	char	*buff;
	char	*cmd;
	//char 	buff[4096];
	int		ret;

	int i = 0;
	//cmd = (char *)malloc(sizeof(char) * (4096));
	cmd = ft_strnew(4096);
	buff = ft_strnew(4096);
	ft_print_prompt();
	if ((ret = (read(0, buff, READ_SIZE))) != -1)
	{
		if (buff[0] == '\n')
		{
			ft_strdel(&cmd);
			ft_strdel(&buff);
			return ;
		}
		if (ft_strchr(buff, (int)'/') != NULL)
			ft_exec_slash(cmd, buff, shell);
		ft_ret_o(ret, shell, cmd, buff);
		if (ft_check_space(buff) == 0)
		{
			while (buff[i] == ' ' && buff[i] != '\n')
				i++;
			if (buff[i] == '\n')
				;
			else
			{
				i = 0;
				while (buff[i] != '\n')
					i++;
				buff[i] = '\0';
				buff = ft_epure(buff);

				ft_print_error(buff ,": Command not found !");
			}
			ft_strdel(&cmd);
			ft_strdel(&buff);
			return ;
		}
		
		if (aff_prompt_next(buff, cmd, shell) == 0)
		{
				ft_strdel(&cmd);
		ft_strdel(&buff);

			return ;
		}
		if (ft_builtin(cmd, shell) == 1)
		{
			//ft_strdel(&cmd);
			//ft_strdel(&buff);
			//ft_free_tab(shell->cmd)
			ft_strdel(&cmd);
		ft_strdel(&buff);

			return ;
		}
		if (ft_builtin(cmd, shell) == 2)
		{	//ft_strdel(&cmd);
		//ft_strdel(&buff);
		ft_free_tab(shell->env);
		ft_free_tab(shell->tab);
		ft_free_tab(shell->cmd);
		ft_strdel(&cmd);
		ft_strdel(&buff);
		ft_strdel(&g_user);
		exit(0);
		}
		//if (ft_verif(shell->tab) == 1)
		/*if(g_path == 1)
		{
			printf("errrreur\n");
			return ;
		}
		else*/
		if (g_path == 0)
			cmd_exec(shell);
		if (g_error == 0)
			;
			//ft_free_tab(shell->cmd);
		else
		{
			printf("la\n");
			ft_strdel(&cmd);
			ft_strdel(&buff);
			//ft_free_tab(shell->cmd);
			return ;
		}
			g_error = 0;
	}
	//	ft_free_tab(shell->cmd);
	//ft_strdel(&buff);
	//ft_strdel(&cmd);
}
