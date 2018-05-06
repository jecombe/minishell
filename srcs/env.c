/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 13:26:51 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 18:35:49 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int		my_getenv(char *name, char **env)
{
	int		i;
	char		*search;
	int		name_len;

	name_len = ft_strlen(name) + 1;
	search = (char*)malloc(sizeof(char) * name_len);
	if (search != NULL)
	{
		ft_strcpy(search, name);
		ft_strcat(search, "=");
		i = 0;
		while (env[i] != NULL)
		{
			if (ft_strncmp(env[i], search, name_len) == 0)
			{
				free(search);
				return (i);
			}
			i = i + 1;
		}
		free(search);
	}
	return (-1);
}


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
		shell->env[j] = ft_strdup(envv[i]);
		i++;
		j++;
	}
	shell->env[j] = NULL;
}
char		**malloc_from_arr(char *str, char **arr)
{
	int		i;
	char		**new_arr;

	i = 0;
	while (arr[i] != NULL)
		i = i + 1;
	new_arr = (char**)malloc(sizeof(char*) * (i + 2));
	if (new_arr == NULL)
		return (arr);
	i = 0;
	while (arr[i] != NULL)
	{
		new_arr[i] = arr[i];
		i = i + 1;
	}
	free(arr);
	new_arr[i] = str;
	new_arr[i + 1] = NULL;
	return (new_arr);
}

char			**ft_set_env_next(t_minishell *shell, char *str)
{
	char *result;
	int len;
	int i = 0;

	len = ft_strlen(shell->cmd[1]) + ft_strlen(str) + 2;
	result = (char *)malloc(sizeof(char) * len);
	ft_strcpy(result, shell->cmd[1]);
	ft_strcat(result,"=");
	ft_strcat(result, str);
	if (ft_strcmp("PATH", shell->cmd[1]) == 0)
	{
		if (ft_verif3(shell->cmd[2]) >= 0 && g_ess == 0)
		{
			g_ess++;
			shell->tab = ft_split(shell->cmd[2]);
			while (shell->tab[i])
			{
				ft_strcat(shell->tab[i], "/");
				i++;
			}

		}
	}
	char		**new_arr;

	if (shell->env == NULL)
	{
		new_arr = (char**)malloc(sizeof(char*) * 2);
		if (new_arr == NULL)
			return (shell->env);
		new_arr[0] = result;
		new_arr[1] = NULL;
	}
	else
		return (malloc_from_arr(result, shell->env));
	return (new_arr);

}

void				ft_set_env(char **env_cmd, t_minishell *shell)
{
	int				i;
	int				p;
	int				j;
	char			*tmp;
	int g = 0;

	j = 0;
	p = -1;
	i = 0;


	while (shell->cmd[j])
		j++;
	if (j > 3)
	{
		ft_print_error("setenv", ": Too much arguments !");
		return;
	}
	j = 0;
	if ((i = my_getenv(env_cmd[1], shell->env)) >= 0)
	{
		p = i;
		if (!shell->cmd[2])
		{
			shell->env = ft_set_env_tool(env_cmd, shell, p, "");
			return;
		}
		else
		{
			shell->env = ft_set_env_tool(env_cmd, shell, p, shell->cmd[2]);
			return ;
		}
	}
	else
	{
		if (!shell->cmd[2])
		{
			shell->env = ft_set_env_next(shell, "");

			return ;
		}
		else
		{
			shell->env = ft_set_env_next(shell, shell->cmd[2]);

			return ;
		}

	}
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


	while (shell->cmd[i])
		i++;
	i = 0;
	if (i > 2)
	{
		ft_print_error("unsetenv", ": Too much arguments !");
		return ;
	}
	while (shell->env[i] != NULL)
	{
		if (ft_match_before_char(shell->cmd[1], '=', shell->env[i]) == 1)
		{
			if (ft_strncmp("PATH=", shell->env[i], 5) == 0)
			{
				if (g_ess > 0)
				{
					ft_free_tab(shell->tab);
					g_ess  = 0;
				}
			}
			ft_realloc_env(shell, i);
			return ;
		}
		i++;
	}
	ft_print_error(shell->cmd[1], ": name doesn't match !");
}
