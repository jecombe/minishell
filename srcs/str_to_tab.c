/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_to_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:47:24 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 16:08:50 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		ft_count(char *str, int value)
{
	int i;
	int co;

	co = 1;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (value == 0)
			if (str[i] == ':' && str[i + 1] != '\0')
				co++;
		if (value == 1)
			if (str[i] == ' ' && str[i + 1] != '\0')
				co++;
		i++;
	}
	return (co);
}

static int		ft_count_char(char *str)
{
	int co;

	co = 0;
	while (str[co] != ' ' && str[co] != '\n' && str[co] != '\0')
		co++;
	co++;
	return (co);
}

char			**ft_str_cmd_quote(char *cmd, t_minishell *shell)
{
	(void)shell;
	return (ft_split_quote(cmd));
}

static char		**ft_str_cmd_next(char *cmd, t_minishell *shell, int i, \
		int co_char)
{
	int a;
	int b;

	b = 0;
	a = 0;
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
			shell->cmd[a][b++] = cmd[i++];
		shell->cmd[a][b] = '\0';
	}
	shell->cmd[a + 1] = NULL;
	return (shell->cmd);
}

char			**ft_str_cmd(char *cmd, t_minishell *shell)
{
	int i;
	int co_word;
	int co_char;

	i = 0;
	co_word = ft_count(cmd, 1);
	shell->cmd = malloc(sizeof(char *) * (co_word) + 1);
	shell->cmd = ft_str_cmd_next(cmd, shell, i, co_char);
	return (shell->cmd);
}
