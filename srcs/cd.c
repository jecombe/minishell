/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 10:39:46 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 11:58:41 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void			ft_transfer(char *env, char *str)
{
	int e;
	int y;

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

void			set_pwd(char **env, char *str, int i)
{
	ft_strdel(&env[i]);
	env[i] = ft_strnew(ft_strlen(str) + 5);
	env[i][0] = 'P';
	env[i][1] = 'W';
	env[i][2] = 'D';
	env[i][3] = '=';
	ft_transfer(env[i], str);
}

void		set_old_pwd(char **env, char *old, int i)
{
	int b;
	int a;

	b = 7;
	a = 4;
	ft_strdel(&env[i]);
	env[i] = ft_strnew(ft_strlen(old) + 8);
	env[i][0] = 'O';
	env[i][1] = 'L';
	env[i][2] = 'D';
	env[i][3] = 'P';
	env[i][4] = 'W';
	env[i][5] = 'D';
	env[i][6] = '=';
	while (old[a])
	{
		env[i][b] = old[a];
		b++;
		a++;
	}
	env[i][b] = '\0';
	free(old);
}

void			ft_chang_pwd(char **env, char *str)
{
	int			i;
	char		*old;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			old = ft_strdup(env[i]);
			set_pwd(env, str, i);
		}
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
			set_old_pwd(env, old, i);
		i++;
	}
}

char			*ft_insert_old(char **env)
{
	char		*ret;
	int			y;
	int			o;
	int			i;

	i = 0;
	y = 7;
	o = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			ret = malloc(sizeof(char *) * (ft_strlen(env[i]) - 7 + 1));
			while (env[i][y])
			{
				ret[o] = env[i][y];
				y++;
				o++;
			}
			ret[o] = '\0';
		}
		i++;
	}
	return (ret);
}

void			ft_cd_next(char *str, char **env, int ok, char *home)
{
	char		cwd[256];

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

void			ft_cd(char *str, char **env, t_minishell *shell)
{
	char		*home;
	char		*r;
	int			ok;

	(void)str;
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
		r = ft_insert_old(env);
		ft_putendl(r);
		chdir(r);
		ft_chang_pwd(env, r);
		free(r);
		ok = 1;
	}
	ft_cd_next(str, env, ok, home);
}
