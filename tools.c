/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 12:57:55 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 16:26:53 by jecombe     ###    #+. /#+    ###.fr     */
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
	shell->cmd = malloc(sizeof(char *) * (co_word) + 1);
	while (cmd[i] && cmd[i] != '\n')
	{
		if (cmd[i] == ' ' || cmd[i] == '\n')
		{
			while (cmd[i] == ' ')
				i++;
			if (cmd[i + 1] != ' ')
				a++;
			b = 0;
		}
		co_char = ft_count_char(cmd + i);
		shell->cmd[a] = (char *)malloc(sizeof(char) * (co_char) + 1);
		while (cmd[i] != ' ' && cmd[i] != '\n' && cmd[i] != '\0')
		{
				shell->cmd[a][b++] = cmd[i++];
		}
		shell->cmd[a][b] = '\0';
	}
		shell->cmd[a + 1] = NULL;
	return (shell->cmd);
}

void		ft_print_prompt(void)
{
	ft_putstr_color("[", 10);
		ft_putstr(STOP);
	ft_putstr_color(user, 14);
		ft_putstr(STOP);
		ft_putstr_color("]", 10);
		ft_putstr(STOP);
	ft_putstr_color("==> ", 9);
		ft_putstr(STOP);
}

void		ft_print_error(const char *s1, const char *s2)
{
		ft_putstr_color(s1, 3);
		ft_putstr(STOP);
		ft_putstr_color(s2, 1);
		ft_putstr(STOP);
		ft_putstr("\n");
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
