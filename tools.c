/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 12:57:55 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:46:26 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_str_cmd(char *cmd, t_minishell *shell)

{
	int i;
	int a;
	int b;
	int co_word;
	int co_char;

	i = 0;
	a = 0;
	b =  0;
	co_word = ft_count(cmd, 1);
	shell->cmd = (char **)malloc(sizeof(char *) * (co_word) + 1);
	while (cmd[i] && cmd[i] != '\n')
	{
		if (cmd[i] == ' ' || cmd[i] == '\n')
		{
			while (cmd[i] == ' ')
				i++;
			a++;
			b = 0;
		}
		co_char = ft_count_char(cmd + i);
		shell->cmd[a] = (char *)malloc(sizeof(char) * (co_char) + 1);
		while (cmd[i] != ' ' && cmd[i] != '\n' && cmd[i] != '\0')
			shell->cmd[a][b++] = cmd[i++];
		shell->cmd[a][b] = '\0';
	}
	shell->cmd[a + 1] = NULL;
	return (shell->cmd);
}

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
		exit(-1);
	if (pid_child == 0)
	{
		signal(SIGINT, sigint);
		while (shell->tab[i])
		{
			file = ft_strcat(shell->tab[i], shell->cmd[0]);
			o = execve(file, shell->cmd, shell->env);
			i++;
		}
		ft_putstr(shell->cmd[0]);
		ft_putendl(": Command not found !");
		exit(0);
	}
	else
		wait(&status);
}
void			ft_putstr_color(char const *s, int nb)
{
	if (s)
	{
		if (nb == 1)
			ft_putstr("\033[0;31m");
		if (nb == 0)
			ft_putstr("\033[1;36m");
		while (*s != '\0')
		{
			ft_putchar(*s);
			s++;
		}
	}
}
