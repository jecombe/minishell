/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:15:33 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/22 16:10:20 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_home(char **env)
{
	char		*result;
	int			i;
	int			a;
	int			b;
	int			ok;

	i = 0;
	a = 5;
	b = 0;
	ok = 0;
	result = (char *)malloc(sizeof(char) * (4096));
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
		{
			ok = 1;
			while (env[i][a] != '\0')
				result[b++] = env[i][a++];
		}
		i++;
	}
	if (ok == 0)
		chdir("/");
	return (result);
}

void			ft_cd(char *str, char **env)
{
	(void)str;
	char *home;

	home = ft_home(env);
	if (str == NULL)
		chdir(home);
	else
	{
		if (chdir(str) == -1)
			ft_print_error(str, ": No such file or directory !");
	}
	free(home);
}
