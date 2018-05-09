/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 15:19:10 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:22:04 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void				ft_exec(char *file, t_minishell *shell)
{
	if (g_test == 0)
	{
		execve(file, shell->cmd, shell->env);
		return ;
	}
	else
		execve(shell->cmd[0], shell->cmd, shell->env);
}

int					ft_file_exec(t_minishell *shell, int value)
{
	if (value == 1 && shell->cmd[0][0] > 33 && shell->cmd[0][0] < 127)
		ft_print_error(shell->cmd[0], ": Command not found !");
	return (0);
}

int					ft_cmd_exec_next(t_minishell *shell, char *file, int value)
{
	if (g_ess == 0 && g_test == 0)
	{
		ft_print_error(shell->cmd[0], ": Command not found !");
		return (0);
	}
	if (g_test == 0)
	{
		if ((file = ft_ser(shell)) == 0)
		{
			ft_file_exec(shell, value);
			return (0);
		}
	}
	return (1);
}

void				ft_transfer(char *env, char *str)
{
	int				e;
	int				y;

	e = 0;
	y = 4;
	while (str[e])
	{
		env[y] = str[e];
		y++;
		e++;
	}
	env[y] = '\0';
}

int					ft_count(char *str)
{
	int i;

	i = 7;
	while (str[i])
		i++;
	return (i);
}
