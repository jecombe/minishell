/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 10:39:46 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 15:20:54 by jecombe     ###    #+. /#+    ###.fr     */
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

void				ft_transfer(char *env, char *str)
{
	int				e;
	int				y;

	e = 0;
	y = 4;
	while (str[e])
	{
		env[y] = str[e];
		y++;
		e++;
	}
	env[y] = '\0';
}

static void			ft_cd_next(char *str, char **env, int ok, char *home)
{
	char			cwd[256];
	int i = 0;

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

void				ft_cd(char *str, char **env, t_minishell *shell)
{
	char			*home;
	char			*r;
	int				ok;
	int				i;
	int				y;

	(void)str;
	i = 0;
	y = 0;
	(void)shell;
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
		while (shell->env[i])
		{
			if (ft_strncmp("OLDPWD=",shell->env[i], 7) == 0)
			{
				y = 7;
				while (shell->env[i][y])
					y++;
				if (y == 7)
				{
					ft_print_error("cd", ": OLDPWD not set !");
					return ;
				}
				r = ft_insert_old(env);
				if (chdir(r) == -1)
					ft_print_error(r, ": No such file or directory !");
				else
					ft_putendl(r);
				ft_chang_pwd(env, r);
				ok = 1;
				ft_cd_next(str, env, ok, home);
				return ;
			}
			i++;
		}
		ft_print_error("cd", ": OLDPWD not set !");
		return ;

	}
	ft_cd_next(str, env, ok, home);
}
