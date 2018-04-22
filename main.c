/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:46 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/22 14:49:46 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		ft_user(char **env)
{
	int i = 0;
	int o;
	int u;

	o = 0;
	u = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "USER=", 5) == 0)
		{
			u = 5;
			user = malloc(sizeof(char *) * ft_strlen(env[i]) - 4);
			while (env[i][u])
			{
				user[o] = env[i][u];
				o++;
				u++;
			}
			user[o] = '\0';
			break;
		}
		i++;
	}
}

int main(int argc, char **argv, char **env)
{
	int ret;
	t_minishell shell;
	int i;
	int o;

	i = 0;
	o = 1;

	init_shell();
	(void)argc;
	(void)argv;
	env_now(&shell, env);
	ft_user(shell.env);
	shell.tab = path(&shell, env);
	shell.tab[0] = split_path(&shell);
	while (shell.tab[o])
	{
		if (ft_strcmp(shell.tab[o], "\n"))
			ft_strcat(shell.tab[o], "/");
		o++;
	}
	while (1)
	{
		signal(SIGINT, sigint);
		aff_prompt(&shell);
	}
	return (0);
}

