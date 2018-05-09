/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pwd.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/27 13:16:28 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:16:07 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		set_pwd(char **env, char *str, int i)
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

void		ft_chang_pwd_next(char *old, char **env, int i, int ok)
{
	while (env[i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 7) == 0)
		{
			if (ok == 0)
				old = ft_strdup("");
			set_old_pwd(env, old, i);
		}
		i++;
	}
}

void		ft_chang_pwd(char **env, char *str)
{
	int		i;
	char	*old;
	int		ok;

	i = 0;
	ok = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			ok = 1;
			old = ft_strdup(env[i]);
			set_pwd(env, str, i);
		}
		i++;
	}
	i = 0;
	ft_chang_pwd_next(old, env, i, ok);
}

char		*ft_insert_old(char **env)
{
	char	*ret;
	int		y;
	int		o;
	int		i;

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
