/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 14:56:37 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 13:56:35 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

static void		ft_check_slashn(char **cmd)
{
	int ok;
	int o;

	ok = 0;
	o = 1;
	while (cmd[o])
	{
		if (ft_strcmp(cmd[o], "\n") == 0)
			ok = 1;
		o++;
	}
	if (ok == 1)
	{
		cmd[o - 1] = "\0";
		ok = 0;
	}
}

static void		ft_print_echo(char **cmd)
{
	int o;

	o = 1;
	while (cmd[o])
	{
		ft_putstr(cmd[o]);
		ft_putstr(" ");
		o++;
	}
	ft_putstr("\n");
}

static int		ft_buitlin_next(t_minishell *shell)
{
	if (ft_strcmp("echo", shell->cmd[0]) == 0)
	{
		ft_check_slashn(shell->cmd);
		ft_print_echo(shell->cmd);
		return (1);
	}
	else if (ft_strcmp("setenv", shell->cmd[0]) == 0)
	{
		ft_set_env(shell->cmd, shell);
		//ft_free_tab(shell->cmd);
		return (1);
	}
	else if (ft_strcmp("unsetenv", shell->cmd[0]) == 0)
	{
		ft_unset_env(shell);
		
		return (1);
	}
	else if (ft_strcmp("env", shell->cmd[0]) == 0)
	{
		int i = 0;
			ft_print_tab(shell->env, 1);
		return (1);
	}
	else
		return (0);
}

int				ft_builtin(char *cmd, t_minishell *shell)
{
	if (ft_strcmp("exit", shell->cmd[0]) == 0)
	{
		/*ft_free(shell->tab, shell->env, shell->cmd);
		ft_strdel(&g_user);
		ft_strdel(&cmd);
		exit(0);*/
		return (2);
	}
	else if (g_p == 1)
	{
		ft_direct(shell->cmd, shell->env, shell, cmd);
		g_p = 0;
		return (1);
	}
	else if (ft_strcmp("cd", shell->cmd[0]) == 0)
	{
		ft_cd(shell->cmd[1], shell->env, shell);
		//ft_strdel(&cmd);
		ft_free_tab(shell->cmd);
		return (1);
	}
	if (ft_buitlin_next(shell) == 0)
		return (0);
	else
		return (1);
}
