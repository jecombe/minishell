/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 10:39:46 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:23:15 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

static char			*ft_home(char **env)
{
	char			*result;
	int				i;
	int				a;
	int				b;
	int				ok;

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

static void			ft_cd_next(char *str, char **env, int ok, char *home)
{
	char			cwd[256];
	int				i;

	i = 0;
	if (chdir(str) == -1)
	{
		if (ok != 1)
			ft_print_error(str, ": No such file or directory !");
	}
	else
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			ft_print_error(NULL, "Can't find the directory !");
		else
			ft_chang_pwd(env, cwd);
	}
	ft_strdel(&home);
}

int					ft_next_cd2(char *str1, char *home, char **env, char *str)
{
	char			*r;
	int				ok;
	int				y;

	if (ft_strncmp("OLDPWD=", str1, 7) == 0)
	{
		y = ft_count(str1);
		if (y == 7)
		{
			ft_print_error("cd", ": OLDPWD not set !");
			free(home);
			return (0);
		}
		r = ft_insert_old(env);
		if (chdir(r) == -1)
			ft_print_error(r, ": No such file or directory !");
		else
			ft_putendl(r);
		ft_chang_pwd(env, r);
		ok = 1;
		ft_cd_next(str, env, ok, home);
		free(r);
		return (0);
	}
	return (1);
}

int					ft_next_cd(t_minishell *shell, char *home, char *str,
		char **env)
{
	int			i;
	char		*r;
	int			y;
	int			ok;

	i = 0;
	y = 0;
	ok = 0;
	while (shell->env[i])
	{
		if (ft_next_cd2(shell->env[i], home, env, str) == 0)
			return (0);
		i++;
	}
	return (1);
}

void				ft_cd(char *str, char **env, t_minishell *shell)
{
	char			*home;
	int				ok;

	(void)str;
	home = ft_home(env);
	ok = 0;
	if (str == NULL)
	{
		ft_chang_pwd(env, home);
		chdir(home);
		ft_strdel(&home);
		return ;
	}
	if (str[0] == '-')
	{
		if (ft_next_cd(shell, home, str, env) == 0)
			return ;
		else
		{
			ft_print_error("cd", ": OLDPWD not set !");
			free(home);
			return ;
		}
	}
	ft_cd_next(str, env, ok, home);
}
