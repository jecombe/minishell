/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 13:26:51 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 12:21:26 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void				env_now(t_minishell *shell, char **envv)
{
	int i;
	int j;
	int result;
	int co;

	i = 0;
	result = 0;
	co = 0;
	j = 0;
	while (envv[i])
	{
		co = ft_strlen(envv[i]);
		result = result + co;
		i++;
	}
	i = 0;
	shell->env = malloc(sizeof(char *) * result);
	while (envv[i] != NULL)
	{
		shell->env[j] = malloc(sizeof(char) * ft_strlen(envv[i]) + 1);
		ft_strcpy(shell->env[j], envv[i]);
		i++;
		j++;
	}
	shell->env[j] = NULL;
}

static void			ft_set_env_next(t_minishell *shell, char **env_cmd, int i)
{
	int j;
	char **tmp;
	char *tt;

	j = 0;
	shell->env[i] = ft_strnew(4096);
	ft_strcpy(shell->env[i], env_cmd[1]);
	shell->env[i] = ft_strcat(shell->env[i], "=");
	if (env_cmd[2])
	{
		ft_strcat(shell->env[i], env_cmd[2]);
		shell->env[i + 1] = NULL;
		if (ft_strcmp("PATH", env_cmd[1]) == 0)
		{
			g_path = 0;
			//ft_free_tab(shell->tab);
			shell->tab = ft_strsplit(shell->cmd[2], ':');
			while (shell->tab[j])
			{
				ft_strcat(shell->tab[j], "/");
				j++;
			}
			return ;


			/*shell->tab = path(shell, env_cmd);
			shell->tab[0] = split_path(shell);
			while (shell->tab[j])
			{
				if (ft_strcmp(shell->tab[j], "\n"))
					ft_strcat(shell->tab[j], "/");
				j++;
			}*/
			j = 0;

		}
	}
}

void				ft_set_env(char **env_cmd, t_minishell *shell)
{
	int				i;
	int				p;
	int				j;
	char			*tmp;

	j = 0;
	p = -1;
	i = 0;
	if (!shell->cmd[1])
	{
		ft_print_error(shell->cmd[0], ": Manques des arguments");
		return ;
	}
	while (shell->env[i])
	{
		if (ft_strncmp(env_cmd[1], shell->env[i], ft_strlen(env_cmd[1])) == 0)
			p = i;
		i++;
	}
	if (p > -1)
	{
		ft_set_env_tool(env_cmd, shell, p, tmp);
		return ;
	}	

	ft_set_env_next(shell, env_cmd, i);
	/*while (shell->cmd[h])
	{
		printf("========> %s\n", shell->cmd[h]);
		h++;
	}*/
}

void				ft_realloc_env(t_minishell *shell, int len)
{
	int				i;
	int				ok;
	char			*c;

	i = -1;
	ok = 0;
	while (++i < len)
	{
		c = ft_strdup(shell->env[i]);
		ft_strdel(&shell->env[i]);
		shell->env[i] = ft_strdup(c);
		ft_strdel(&c);
	}
	ft_strdel(&shell->env[i]);
	ok = 1;
	i++;
	while (shell->env[i])
	{
		c = ft_strdup(shell->env[i]);
		shell->env[i - 1] = ft_strdup(c);
		ft_strdel(&c);
		i++;
	}
	shell->env[i - 1] = NULL;
	return ;
}

void				ft_unset_env(t_minishell *shell)
{
	int				i;
	int				p;

	p = 0;
	i = 0;
	if (!shell->cmd[1])
	{
		ft_print_error(shell->cmd[0], ": Manques des arguments");
		return ;
	}
	while (shell->env[i] != NULL)
	{
		if (ft_match_before_char(shell->cmd[1], '=', shell->env[i]) == 1)
		{
			if (ft_strncmp("PATH=", shell->env[i], 5) == 0)
			{
				g_path = 1;
			ft_free_tab(shell->tab);	
			}
			ft_realloc_env(shell, i);
			return ;
		}
		i++;
	}
	ft_print_error(shell->cmd[1], ": name doesn't match !");
}
