/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:20:22 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:20:52 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <sys/types.h>
#include <sys/stat.h>

void				ft_ser_next(char *dup, char *dup2, char *dup3)
{
	if (dup3 && dup2 && dup != NULL)
	{
		free(dup3);
		free(dup2);
		free(dup);
	}
}

char				*ft_ser(t_minishell *shell)
{
	int				i;
	char			*dup;
	char			*dup2;
	char			*dup3;
	struct stat		sb;

	i = 0;
	while (shell->tab[i])
	{
		dup3 = ft_strdup(shell->tab[i]);
		dup2 = ft_strdup(shell->cmd[0]);
		dup = ft_strjoin(dup3, dup2);
		if (lstat(dup, &sb) == -1)
			;
		else
		{
			ft_strdel(&dup2);
			ft_strdel(&dup3);
			return (dup);
		}
		ft_ser_next(dup, dup2, dup3);
		i++;
	}
	return (0);
}

void				ft_next_next(pid_t pid_child, char *file,
		t_minishell *shell)
{
	if (pid_child > 0)
	{
		wait(0);
		if (g_test == 0)
			ft_strdel(&file);
	}
	else
		ft_exec(file, shell);
}

void				cmd_exec(t_minishell *shell, int value)
{
	pid_t			pid_child;
	char			*file;
	int				i;
	int				status;

	i = 0;
	if (g_ess == 0 && g_test == 0)
	{
		ft_print_error(shell->cmd[0], ": Command not found !");
		return ;
	}
	if (g_test == 0)
	{
		if ((file = ft_ser(shell)) == 0)
		{
			ft_file_exec(shell, value);
			return ;
		}
	}
	pid_child = fork();
	ft_next_next(pid_child, file, shell);
	g_test = 0;
	return ;
}

void				ft_direct(char **cmd, char **env, t_minishell *shell, \
		char *buff)
{
	(void)cmd;
	(void)env;
	(void)shell;
	(void)buff;
	if (access(cmd[0], F_OK) == 0)
	{
		g_test = 1;
		cmd_exec(shell, 0);
	}
	else
		ft_print_error(shell->cmd[0], ": No such file or directory !");
}
