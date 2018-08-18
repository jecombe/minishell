/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dollar.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/10 17:39:12 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 12:11:17 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

static void			ft_match_env_next(char *tempenv, int o, int j,
		t_minishell *shell)
{
	int				i;

	i = 0;
	tempenv[o] = '\0';
	while (shell->env[i])
	{
		if (ft_match_before_char(tempenv, '=', shell->env[i]) == 1)
		{
			while (shell->env[i][j])
			{
				ft_putchar(shell->env[i][j]);
				j++;
			}
			ft_putchar(' ');
		}
		i++;
	}
}

int					ft_ok_space(char *str)
{
	int ok;
	int i;

	ok = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			ok++;
		i++;
	}
	return (ok);
}

void				ft_match_env(char *strenv, t_minishell *shell)
{
	char			*tempenv;
	int				i;
	int				o;
	int				j;
	int				ok;

	i = 1;
	o = 0;
	j = 0;
	ok = 0;
	(void)shell;
	tempenv = (char *)malloc(sizeof(char) * (ft_strlen(strenv) + 1));
	if (ft_ok_space(strenv) == 0)
		i = 1;
	else
		i = 0;
	while (strenv[i])
	{
		tempenv[o] = strenv[i];
		i++;
		o++;
	}
	j = i;
	ft_match_env_next(tempenv, o, j, shell);
	free(tempenv);
}

void				ft_search_dollar(t_minishell *shell)
{
	int i;
	int o;

	i = 0;
	o = 0;
	while (shell->cmd[i])
	{
		while (shell->cmd[i][o])
		{
			if (shell->cmd[i][o] == '$')
			{
				ft_match_env(shell->cmd[i], shell);
			}
			o++;
		}
		o = 0;
		i++;
	}
}
