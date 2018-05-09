/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 13:26:51 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:33:15 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int						ft_set_env_get_env(t_minishell *shell, char **env_cmd,
		int p)
{
	int i;

	if ((i = my_getenv(env_cmd[1], shell->env)) >= 0)
	{
		p = i;
		if (!shell->cmd[2])
		{
			shell->env = ft_set_env_tool(env_cmd, shell, p, "");
			return (1);
		}
		else
		{
			shell->env = ft_set_env_tool(env_cmd, shell, p, shell->cmd[2]);
			return (1);
		}
	}
	else
	{
		ft_suite(shell);
		return (1);
	}
	return (0);
}

void					ft_set_env(char **env_cmd, t_minishell *shell)
{
	int					i;
	int					p;
	int					j;
	char				*tmp;
	int					g;

	j = 0;
	p = -1;
	i = 0;
	g = 0;
	while (shell->cmd[j])
		j++;
	if (j == 1)
	{
		ft_print_error("setenv", ": No arguments !");
		return ;
	}
	if (j > 3)
	{
		ft_print_error("setenv", ": Too much arguments !");
		return ;
	}
	j = 0;
	if (ft_set_env_get_env(shell, env_cmd, p) == 1)
		return ;
}

void					ft_realloc_env(t_minishell *shell, int len)
{
	int					i;
	char				*c;

	i = -1;
	while (++i < len)
	{
		c = ft_strdup(shell->env[i]);
		ft_strdel(&shell->env[i]);
		shell->env[i] = ft_strdup(c);
		ft_strdel(&c);
	}
	ft_strdel(&shell->env[i]);
	i++;
	while (shell->env[i])
	{
		c = ft_strdup(shell->env[i]);
		ft_strdel(&shell->env[i]);
		shell->env[i - 1] = ft_strdup(c);
		ft_strdel(&c);
		i++;
	}
	shell->env[i - 1] = NULL;
	return ;
}

int						ft_unset_env_next(t_minishell *shell, int i)
{
	while (shell->env[i] != NULL)
	{
		if (ft_match_before_char(shell->cmd[1], '=', shell->env[i]) == 1)
		{
			if (ft_strncmp("PATH=", shell->env[i], 5) == 0)
			{
				if (g_ess > 0)
				{
					ft_free_tab(shell->tab);
					g_ess = 0;
				}
			}
			ft_realloc_env(shell, i);
			return (0);
		}
		i++;
	}
	return (1);
}

void					ft_unset_env(t_minishell *shell)
{
	int					i;
	int					p;

	p = 0;
	i = 0;
	while (shell->cmd[i])
		i++;
	if (i == 1)
	{
		ft_print_error("unsetenv", ": No arguments !");
		return ;
	}
	if (i > 2)
	{
		ft_print_error("unsetenv", ": Too much arguments !");
		return ;
	}
	i = 0;
	if (ft_unset_env_next(shell, i) == 0)
		return ;
	ft_print_error(shell->cmd[1], ": name doesn't match !");
}
