/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:15:33 by jecombe      #+#   ##    ##    #+#       */
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
void			ft_chang_pwd(char **env, char *str)
{
	int i;
	int e;
	char *old;

	e = 0;
	i = 0;

	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
		
			old = ft_strdup(env[i]);
		
			ft_strdel(&env[i]);
			env[i] = ft_strnew(ft_strlen(str) + 5);
			env[i][0] = 'P';
			env[i][1] = 'W';
			env[i][2] = 'D';
			env[i][3] = '=';
			int y =  4;
			while (str[e])
			{
				env[i][y] = str[e];
				y++;
				e++;
			}
			env[i][y] = '\0';
		}
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{

			ft_strdel(&env[i]);
			env[i] = ft_strnew(ft_strlen(old) + 8);
			int a = 4;
			int b = 7;
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
		}
		i++;
	}
}


char			*ft_insert_old(char **env)
{
	char *ret;
	int i;
	
	i = 0;;
	while (env[i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			int y = 7;
			int o = 0;
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
void			ft_cd(char *str, char **env, t_minishell *shell)
{
	(void)str;
	(void)shell;
	char *home;
	char cwd[256];
	char *r;

	home = ft_home(env);
	if (str == NULL)
	{
		ft_chang_pwd(env, home);
		chdir(home);
	}
	if (str[0] == '-')
	{
		r = ft_insert_old(env);
		ft_putendl(r);
		chdir(r);
		ft_chang_pwd(env, r);
		free(r);

	}
	else
	{
		if (chdir(str) == -1)
			ft_print_error(str, ": No such file or directory !");
		else
		{
			if (getcwd(cwd, sizeof(cwd)) == NULL)
				ft_putendl("Can't find the direcoty !");
			else
				ft_chang_pwd(env, cwd);
		}
	}
	ft_strdel(&home);
}
