/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tild.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/10 17:41:04 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 18:10:04 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void			ft_tild3(char *str, char *tild, char *hometemp, int o)
{
	int i;

	i = 1;
	while (str[i])
	{
		tild[o] = str[i];
		o++;
		i++;
	}
	tild[o] = '\0';
	ft_strcat(hometemp, "/");
	ft_strcat(hometemp, tild);
	if (chdir(hometemp) == -1)
		ft_print_error(hometemp, ": No such user or named directory !");
}

void			ft_tild2(char *home, char *str, char *tild)
{
	int			o;
	int			i;
	char		hometemp[PATH_MAX];

	o = 0;
	i = 1;
	hometemp[0] = '/';
	o++;
	while (home[i] != '/')
	{
		hometemp[o] = home[i];
		o++;
		i++;
	}
	hometemp[o] = '\0';
	o = 0;
	i = 1;
	ft_tild3(str, tild, hometemp, o);
}

void			ft_tild1(char *str, char *tild, char *home, char **env)
{
	int o;
	int i;

	o = 0;
	i = 1;
	while (str[i])
	{
		tild[o] = str[i];
		o++;
		i++;
	}
	tild[o] = '\0';
	if (str[1] == '/')
	{
		ft_strcat(home, tild);
		if (chdir(home) == -1)
			ft_print_error(home, ": No such user or named directory !");
		ft_chang_pwd(env, home);
	}
	else
		ft_tild2(home, str, tild);
}

int				ft_tild(char *str, t_minishell *shell, char *home, char **env)
{
	char		tild[PATH_MAX];
	char		hometemp[PATH_MAX];
	int			i;
	int			o;

	(void)shell;
	if (str[0] == '~' && str[1] == '\0')
	{
		ft_chang_pwd(env, home);
		chdir(home);
		ft_strdel(&home);
		return (0);
	}
	ft_tild1(str, tild, home, env);
	free(home);
	return (0);
}
