/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 14:56:37 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 18:35:41 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
char		*ft_home(char **env)
{
	char *result;
	int i;
	int a;
	int b;
	int ok;

	i = 0;
	ok = 0;
	result = (char *)malloc(sizeof(char) * (4096));
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
		{
			ok = 1;
			a = 5;
			b = 0;
			while (env[i][a] != '\0')
				result[b++] = env[i][a++];
			printf("OOOOOOOO %s\n", result);
		}
		i++;
	}
	if (ok == 0)
		chdir("/");
	return (result);
}

void		ft_cd(char *str, char **env)
{
	(void)str;
	char *home;

	home = ft_home(env);
	if (str == NULL)
		chdir(home);
	else
	{
		if (chdir(str) == -1)
			ft_putendl("No such file or directory");
	}
	free(home);
}
int			ft_builtin(char *cmd, t_minishell *shell)
{
	if (ft_strcmp("exit\n", cmd) == 0)
		exit(0);
	else if (ft_strcmp("cd", shell->cmd[0]) == 0)
	{
		ft_cd(shell->cmd[1], shell->env);
		return(1);
	}
	else
		return (0);
}
