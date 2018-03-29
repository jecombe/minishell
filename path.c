/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 14:41:54 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 17:38:10 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			ft_check_path(char **env)
{
	int ok;
	int compare;
	int i;

	i = 0;
	ok = 0;
	compare = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			ok = 1;
		i++;
	}
	if (ok == 0)
	{
		ft_putendl("PATH is not set");
		exit(0);
	}
	return (ok);

}

int			ft_count(char *str, int value)
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

int			ft_count_char(char *str)
{
	int co;
	co = 0;
	while (str[co] != ' ' && str[co] != '\n' && str[co] != '\0')
		co++;
	co++;
	return (co);

}

void		in_tab(t_minishell *shell, char *env)
{
	int i;
	int a;
	int b;
	int l;
	int co_word;
	int co_char;

	i = 5;
	a = 0;
	b =  0;
	l = 0;
	co_word = ft_count(env, 0);
	shell->tab = (char **)malloc(sizeof(char *) * (co_word) + 1);
	while (env[i] && env[i] != '\n')
	{
		if (env[i] == ':' || env[i] == '\n')
		{
			while (env[i] == ':')
				i++;
			a++;
			b = 0;
		}
		co_char = ft_count_char(env + i);
		shell->tab[a] = (char *)malloc(sizeof(char) * (co_char) + 1);
		while (env[i] != ':' && env[i] != '\n' && env[i] != '\0')
			shell->tab[a][b++] = env[i++];
		shell->tab[a][b] = '\0';
		ft_strcat(shell->tab[a], "/");
	}
	shell->tab[a + 1] = NULL;
	while (shell->tab[l])
	{
		printf("%s\n", shell->tab[l]);
		l++;
	}
}

void		path(t_minishell *shell, char **env)
{
	int i;
	int checkPath;
	int compare;
	(void)shell;

	checkPath = ft_check_path(env);
	if (checkPath == 1)
	{
		compare = 0;
		i = 0;
		while (shell->env[i] != NULL)
		{
			if ((compare = (ft_strncmp("PATH=", shell->env[i], 5) == 0)))
			{
				in_tab(shell, shell->env[i]);
			}
			i++;
		}

	}
}

