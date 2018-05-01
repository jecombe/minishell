/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:20:22 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 16:34:31 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <sys/types.h>
#include <sys/stat.h>

char			*ft_ser(t_minishell *shell)
{
	int			i;
	char		*temp;
	char *dup;
	struct stat sb;

	i = 0;
	temp = NULL;

	while (shell->tab[i])
		{
			dup = ft_strdup(shell->tab[i]);
			ft_strcat(dup, shell->cmd[0]);
			if (lstat(dup, &sb) == -1)
			{
				free(dup);
			}
			else
			{
				//temp = dup;
				//free(dup);
				return (dup);
			}
			i++;
		}
	return (0);
}
int g_test;

void			cmd_exec(t_minishell *shell)
{
	pid_t		pid_child;
	char	*file;
	int			i;
	int			status;

	i = 0;
	if (g_test == 0)
		if ((file = ft_ser(shell)) == 0 || !shell->tab)
		{
			free(file);
			g_error = 1;
			int i = 0;
			ft_print_error(shell->cmd[0], ": Command not found !");
			return;
		}
	pid_child = fork();
	if (pid_child > 0)
		wait(0);
	else
	{
		if (g_test == 0)
		{
			execve(file, shell->cmd, shell->env);
			//ft_strdel(&file);
			return ;
		}
		else
		{
			execve(shell->cmd[0], shell->cmd, shell->env);
		}

	}
	g_error = 0;
		g_test = 0;
		//ft_strdel(&file);
	return ;

}

void			ft_direct(char **cmd, char **env, t_minishell *shell, \
		char *buff)
{
	(void)cmd;
	(void)env;
	(void)shell;
	(void)buff;
	if (access(cmd[0], F_OK) == 0)
	{
		g_test = 1;
		cmd_exec(shell);
		
	}
	else
		ft_print_error(shell->cmd[0], ": No such file or directory !");
}
