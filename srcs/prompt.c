/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:36 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 18:34:20 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_exec_slash(char *cmd, t_minishell *shell)
{
	int t;

	t = 0;
	//cmd = ft_epure(buff);
	if (cmd[0] == '/')
	{
		g_p = 1;
		while (cmd[t] != '\0')
	{
		if (cmd[t] == ' ' && cmd[t + 1] == '\n')
			cmd[t] = '\n';
		t++;
	}
	t = 0;
	shell->cmd = ft_str_cmd(cmd, shell);

		ft_builtin(cmd, shell);
		return ;
	}
}

void		aff_prompt_next2(char *cmd, t_minishell *shell, int t, char *buff)
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
	//shell->cmd = ft_str_cmd(cmd, shell)	printf("--> %s--\n", cmd);
		shell->cmd = ft_strsplit2(cmd);
}

int			aff_prompt_next(char *buff, char *cmd, t_minishell *shell)
{
	int co;
	int prime;
	int t;

	t = 0;

	co = ft_check_quote(buff);
	if (co > 0)
	{
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
		//ft_print_tab(shell->cmd);
	}
	}
	else
		aff_prompt_next2(cmd, shell, t, buff);
	return (1);
}

void		ft_ret_o(int ret, t_minishell *shell, char *cmd, char *buff)
{
	(void)shell;
	(void)cmd;
	(void)buff;
	if (ret != 0)
	{
		return;
	}
	if (ret == 0)
	{
		ft_putchar('\n');
		ft_putchar('\r');
		ft_strdel(&g_user);
		ft_strdel(&buff);
	ft_strdel(&cmd);
	ft_free_tab(shell->env);
		ft_free_tab(shell->tab);
		//ft_putchar('\r');

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
	char	*cmd2;
	int ok;
	//char 	buff[4096];
	int		ret;

	int i = 0;
	cmd = malloc(sizeof(char*) * (4096));
	cmd2 = malloc(sizeof(char*) * (4096));
	buff = malloc(sizeof(char *) * (4096));
	//cmd = ft_strnew(4096);
	//cmd2 = ft_strnew(4096);
	//buff = ft_strnew(4096);
	char *cmd3;
	cmd3 = (char *)malloc(sizeof(char) * (4096));
	ok = 0;
	ft_print_prompt();
	if ((ret = (read(0, buff, READ_SIZE))) != -1)
	{
		/*if (buff[0] == '\0')
			printf("FUCK\n");*/
		if (buff[0] == '\n')
		{
			ft_strdel(&cmd);
			ft_strdel(&buff);
			free(cmd2);
				free(cmd3);


			return ;
		}
			//cmd2 = ft_epure(buff);
		if (ft_strchr(buff, (int)'/') != NULL)
		{
			cmd3 = ft_strdup(buff);
			cmd2 = ft_epure(buff);
			if (cmd2[0] == '/')
			{
				ft_exec_slash(cmd2, shell);
				free(cmd2);
				free(cmd3);
				free(cmd);
				//free(buff);

			return ;
			}
		}
		ft_ret_o(ret, shell, cmd, buff);
		if (ft_check_space(buff) == 0)
		{
			ft_strdel(&cmd);
			ft_strdel(&buff);
			return ;
		}
		
		if (aff_prompt_next(buff, cmd, shell) == 0)
		{
			return ;
		}
		if (ft_builtin(cmd, shell) == 1)
		{
		//free(&cmd2);
			//free(&cmd3);

		//free(&buff);
			//free(&cmd);
			return ;
		}
		if (ft_builtin(cmd, shell) == 2)
		{	
		ft_free_tab(shell->env);
		ft_free_tab(shell->tab);
		//ft_free_tab(shell->cmd);
		ft_strdel(&g_user);
		exit(0);
		}
		//if (g_ess > 0)
		//{
			//ft_print_tab(shell->tab);
			cmd_exec(shell, 1);
			/*ft_strdel(&cmd);
			ft_strdel(&cmd2);
			ft_strdel(&cmd3);
			ft_strdel(&buff);
		ft_free_tab(shell->cmd);*/
		//}
		//else
			return;
	}
}
