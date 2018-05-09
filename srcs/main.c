/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:46 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:06:55 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void			ft_user(char **env)
{
	int i;
	int o;
	int u;

	o = 0;
	u = 0;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "USER=", 5) == 0)
		{
			u = 5;
			g_user = malloc(sizeof(char *) * ft_strlen(env[i]) - 4);
			while (env[i][u])
			{
				g_user[o] = env[i][u];
				o++;
				u++;
			}
			g_user[o] = '\0';
			break ;
		}
		i++;
	}
}

void			ft_init(t_minishell *shell, char **env)
{
	int o;

	o = 1;
	env_now(shell, env);
	ft_user(shell->env);
	g_ess++;
	shell->tab = path(shell, env);
	shell->tab[0] = split_path(shell);
	while (shell->tab[o])
	{
		if (ft_strcmp(shell->tab[o], "\n"))
			ft_strcat(shell->tab[o], "/");
		o++;
	}
}

int				main(int argc, char **argv, char **env)
{
	t_minishell shell;
	int			i;
	int			o;

	i = 0;
	o = 1;
	signal(SIGINT, sigint);
	init_shell();
	(void)argc;
	(void)argv;
	ft_init(&shell, env);
	while (1)
	{
		signal(SIGINT, sigint);
		aff_prompt(&shell);
	}
	return (0);
}
