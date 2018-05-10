/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dollar.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/10 17:39:12 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 19:18:08 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

static void			ft_match_env_next(char *tempenv, int o, int j,
		t_minishell *shell)
{
	int				i;
	int u = 0;

	int t = 0;
	int y = 0;
	int ok = 0;
	int rr = 0;
	int space = 0;
	int space_end = 0;
	i = 0;
	int jj = 0;
	tempenv[o] = '\0';
	/*while (tempenv[u])
	{
		if (tempenv[u] == ' ')
			ok++;
		u++;
	}
	u = 0;
	if (ok > 0)
	{
		while (tempenv[u] == ' ')
			u++;
		space = u;
		while (tempenv[u])
		{
			if (tempenv[u] == ' ')
				space_end++;
			u++;
		}
		u = 0;
		char *res_temp_env;

		while (tempenv[u] == ' ')
			u++;
		rr = u;
		while (tempenv[u] != ' ')
		{
			jj++;
			u++;
		}
		res_temp_env = (char *)malloc(sizeof(char) * (jj + 1));
		rr++;
		while (tempenv[rr] != ' ')
		{
			res_temp_env[t] = tempenv[rr];
			rr++;
			t++;
		}
		res_temp_env[t] = '\0';
		while (shell->env[i])
	{
		if (ft_match_before_char(res_temp_env, '=', shell->env[i]) == 1)
		{
			j = t + 1;
			while (space != 0)
			{
				ft_putchar(' ');
				space--;
			}
			while (shell->env[i][j])
			{

				ft_putchar(shell->env[i][j]);
				j++;
			}
			if (space_end > 0)
			{
				while (space_end != 0)
				{
					ft_putchar(' ' );
					space_end--;
				}
			}
			else
				ft_putchar(' ');
		}
		i++;
	}
		return ;
}*/
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
	while (strenv[i])
	{
		if (strenv[i] == ' ')
			ok++;
		i++;
	}
	tempenv = (char *)malloc(sizeof(char) * (i + 1));
	if (ok == 0)
		i = 1;
	else
		i = 0;
	while (strenv[i])
	{
		tempenv[o] = strenv[i];
		i++;
		o++;
	}
	j = i + 1;
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
