/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:20:22 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 13:13:08 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_fork(t_minishell *shell)
{
	pid_t pid_child;
	const char *file;
	int i;
	int status;
	int o;

	i  = 0;
	pid_child = fork();
	if (pid_child == -1)
		exit(EXIT_FAILURE);
	if (pid_child == 0)
	{
		signal(SIGINT, sigint);
		while (shell->tab[i])
		{
			file = ft_strcat(shell->tab[i], shell->cmd[0]);
			o = execve(file, shell->cmd, shell->env);
			i++;
		}
		ft_print_error(shell->cmd[0], ": Command not found !");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

void		cmd_exec(char *exec, char **input, char **env)
{
	pid_t pid;
	pid = fork();
	if (pid > 0)
	wait(0);
	else
	execve(exec, input, env);
}

void		ft_direct(char **cmd, char **env, t_minishell *shell, char *buff)
{
	(void)cmd;
	(void)env;
	(void)shell;
	(void)buff;
	int y = 0;
	int i = 0;
	int o = 0;
	if (access(cmd[0], F_OK) == 0)
	cmd_exec(cmd[0], cmd, env);
	else
		ft_print_error(shell->cmd[0], ": No such file or directory !");
}
