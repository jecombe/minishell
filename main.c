#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAXCOM 1000
#define MAXLIST 100
#include "libft/libft.h"
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void		printDir(void)
{
	char	cwd[1024];
	getcwd(cwd, sizeof(cwd));
}
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
	i = 0;
	j = 0;
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

int main(int argc, char **argv, char **env)
{
	int ret;
	t_minishell shell;
	init_shell();
	env_now(&shell, env);
	while (1)
	{
		printDir();

	}
}

