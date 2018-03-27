/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:46 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 18:13:25 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		init_shell(void)
{
	ft_putendl("---------------------------------");
	ft_putendl("|	MINISHELL		|");
	ft_putendl("|				|");
	ft_putendl("|				|");
	ft_putendl("|				|");
	ft_putendl("|				|");
	ft_putendl("---------------------------------");
}

void			env_now(t_minishell *shell, char **envv)
{
	int i;
	int j;
	int l;
	int g;
	i = 0;
	j = 0;
	l = 0;
	g = 0;
	shell->env = malloc(sizeof(char *) * (200));
	while (envv[i] != NULL)
	{
		shell->env[j] = malloc(sizeof(char) * ft_strlen(envv[i]) + 1);
		ft_strcpy(shell->env[j], envv[i]);
		i++;
		j++;
	}
	shell->env[j] = NULL;
}

void			sigint(int sig)
{
	(void)sig;
	ft_putchar('\n');
	ft_putstr("$> ");
}

int main(int argc, char **argv, char **env)
{
	int ret;
	t_minishell shell;

	(void)argc;
	init_shell();
	env_now(&shell, env);
	path(&shell, env);
	while (1)
	{
		signal(SIGINT, sigint);
		aff_prompt(argv, &shell);

	}
	return (0);
}

