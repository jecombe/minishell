/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_env.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 15:28:17 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:36:18 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

int						my_getenv(char *name, char **env)
{
	int				i;
	char			*search;
	int				name_len;

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

void					env_now(t_minishell *shell, char **envv)
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

char					**malloc_from_arr(char *str, char **arr)
{
	int				i;
	char			**new_arr;

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

void					ft_set_env_next_next(t_minishell *shell)
{
	int i;

	i = 0;
	if (ft_strcmp("PATH", shell->cmd[1]) == 0)
	{
		if (ft_verif3(shell->cmd[2], 1) >= 0 && g_ess == 0)
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
}
