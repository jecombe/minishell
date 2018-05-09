/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_env_2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 15:31:57 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:38:15 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char					**ft_set_env_next(t_minishell *shell, char *str)
{
	char			*result;
	int				len;
	char			**new_arr;

	len = ft_strlen(shell->cmd[1]) + ft_strlen(str) + 2;
	result = (char *)malloc(sizeof(char) * len);
	ft_strcpy(result, shell->cmd[1]);
	ft_strcat(result, "=");
	ft_strcat(result, str);
	ft_set_env_next_next(shell);
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
	free(result);
	return (new_arr);
}

void					ft_suite(t_minishell *shell)
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
