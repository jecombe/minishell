/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:46 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 15:22:46 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		init_shell(void)
{
	ft_putstr_color("---------------------------------", 1);
	ft_putstr("\033[0m");
	ft_putstr("\n");
	ft_putstr_color("|	MINISHELL		|", 0);
	ft_putstr("\n");
	ft_putstr_color("|	Jecombe			|", 0);
	ft_putstr("\n");
	ft_putstr_color("|				|", 0);
	ft_putstr("\n");
	ft_putstr_color("|				|", 0);
	ft_putstr("\n");
	ft_putstr_color("|				|", 0);
	ft_putstr("\033[0m");
	ft_putstr("\n");


	ft_putstr_color("---------------------------------", 1);
	ft_putstr("\033[0m");
	ft_putstr("\n");
}

void			env_now(t_minishell *shell, char **envv)
{
	int i;
	int j;
	int result = 0;
	int co = 0;
	i = 0;
	j = 0;
	while (envv[i])
	{
		co = ft_strlen(envv[i]);
		result = result + co ;
		i++;
	}
	i = 0;
	shell->env = malloc(sizeof(char *) * result);
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
	ft_putstr("🤠 $> ");
}

char		*split_path(t_minishell *shell)
{
	int i;
	int o;
	o = 0;
	int j;
	j=  0;
	i = 5;
	while (shell->tab[0][i] != '\0')
	{
		shell->tab[0][j] = shell->tab[0][i];
		j++;
		i++;
	}
	shell->tab[0][j] = '/';
	shell->tab[0][j + 1] = '\0';
	return (shell->tab[0]);


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

