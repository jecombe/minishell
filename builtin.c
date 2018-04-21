/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 14:56:37 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 14:31:32 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"
char		*ft_home(char **env)
{
	char *result;
	int i;
	int a;
	int b;
	int ok;

	i = 0;
	ok = 0;
	result = (char *)malloc(sizeof(char) * (4096));
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 5) == 0)
		{
			ok = 1;
			a = 5;
			b = 0;
			while (env[i][a] != '\0')
				result[b++] = env[i][a++];
		}
		i++;
	}
	if (ok == 0)
		chdir("/");
	return (result);
}

void		ft_cd(char *str, char **env)
{
	(void)str;
	char *home;

	home = ft_home(env);
	if (str == NULL)
		chdir(home);
	else
	{
		if (chdir(str) == -1)
		{
			ft_putstr_color(str, 3);
		ft_putstr(STOP);
		ft_putstr_color(": No such file or directory", 1);
		ft_putstr(STOP);
		ft_putstr("\n");
		}

	}
	free(home);
}

void		ft_set_env(char **env_cmd, t_minishell *shell)
{
	int i;
	int p;
	int j = 0;
	char *tmp;

	p = -1;
	i = 0;
	while(shell->env[i])
	{
		if (ft_strncmp(env_cmd[1], shell->env[i], ft_strlen(env_cmd[1])) == 0)
			p = i;
		i++;
	}
	if (p > -1)
	{
		if (!env_cmd[2])
			env_cmd[2] = ft_strdup("");
		else
			tmp = ft_strdup(env_cmd[2]);
		free(shell->env[p]);
		shell->env[p] = ft_strdup(env_cmd[1]);
		ft_strcat(shell->env[p], "=");
		ft_strcat(shell->env[p], env_cmd[2]);
		return ;
	}
	shell->env[i] = env_cmd[1];
	ft_strcat(shell->env[i], "=");

	if (env_cmd[2])
	{
		ft_strcat(shell->env[i], env_cmd[2]);
		shell->env[i + 1] = NULL;
		if (ft_strncmp("PATH=", env_cmd[1], 5) == 0)
		{
			shell->tab = path(shell, env_cmd);
			shell->tab[0] = split_path(shell);
			while (shell->tab[j])
			{
				if (ft_strcmp(shell->tab[j], "\n"))
					ft_strcat(shell->tab[j], "/");
				j++;
			}
		}
	}
}

void		ft_realloc_env(t_minishell *shell, int len)
{
	int i;
	int ok = 0;
	i = 0;
	char *c;
	while (i < len)
	{
		c = ft_strdup(shell->env[i]);
		ft_strdel(&shell->env[i]);
		shell->env[i] = c;
		i++;
	}
	free(shell->env[i]);
	ok = 1;
	i = i +1;
	while (shell->env[i])
	{
		c = ft_strdup(shell->env[i]);
		shell->env[i - 1] = c;
		i++;
	}
	shell->env[i - 1] = NULL;
	return;

}

int		ft_search_break(char *cmd, char c, char *env)
{
	int i;
	int y;
	i = 0;
	y = 0;

	while (env[i + 1] != c && cmd[y] == env[i])
	{
			i++;
			y++;
	}
	if (cmd[y] != env[i])
		return (0);
	return(1);
}
void		ft_unset_env(char **env, t_minishell *shell)
{
	int i;
	int j = 0;
	int ok = 0;
	(void)env;
	int compare;
	compare = 0;
	int p = 0;
	i = 0;
	int len = ft_strlen(shell->cmd[1]);
	while (shell->env[i] != NULL)
	{
		if (ft_search_break(shell->cmd[1], '=', shell->env[i]) == 1)
		{
			if (ft_strncmp("PATH=", shell->env[i], 5) == 0)
			{
				int p = 0;
				while (shell->tab[p])
				{
					ft_strdel(&shell->tab[p]);
					p++;
				}
				free(shell->tab);
			}
			ft_realloc_env(shell, i);
			p = 0;
			return;
		}
		i++;
	}
	ft_putstr_color(shell->cmd[1], 3);
		ft_putstr(STOP);
	ft_putstr_color(": name doesnt't match !", 1);
		ft_putstr(STOP);
		ft_putstr("\n");
}
int		ft_inspect_echo(char *str)
{
	int i;
	int j;

	j = 0;
	char **test;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			break;
		ft_putstr(str);
		i++;
	}
	return (0);
}
void		cmd_exec(char *exec, char **input, char **env)
{
	pid_t pid;
	pid = fork();
	if (pid > 0)
	wait(0);
	else
	execve(exec, input, env);
}
void		ft_direct(char **cmd, char **env, t_minishell *shell, char *buff)
{
	(void)cmd;
	(void)env;
	(void)shell;
	(void)buff;
	int y = 0;
	int i = 0;
	int o = 0;
	if (access(cmd[0], F_OK) == 0)
	cmd_exec(cmd[0], cmd, env);
	else
	{
		ft_putstr_color(shell->cmd[0], 3);
		ft_putstr(STOP);
		ft_putstr_color(": No such file or directory !", 1);
		ft_putstr(STOP);
		ft_putstr("\n");
	}

}
int			ft_builtin(char *cmd, t_minishell *shell)
{
	int o =1;
	int ok = 0;
	if (ft_strcmp("exit\n", cmd) == 0)
		exit(0);
	else if (g_p == 1)
	{
		ft_direct(shell->cmd, shell->env, shell, cmd);
		g_p = 0;
		return (1);
	}

	else if (ft_strcmp("cd", shell->cmd[0]) == 0)
	{
		ft_cd(shell->cmd[1], shell->env);
		return (1);
	}
	else if (ft_strcmp("echo", shell->cmd[0]) == 0)
	{
		o = 0;
		while (shell->cmd[o])
		{
			if (ft_strcmp(shell->cmd[o], "\n") == 0)
			{
				ok = 1;
			}
			o++;
		}
		if (ok == 1)
		{
			shell->cmd[o - 1] = "\0";
			ok  = 0;
		}
		o = 1;
		while (shell->cmd[o])
		{
				ft_putstr(shell->cmd[o]);
				ft_putstr(" ");
			o++;
		}
		ft_putstr("\n");
		return (1);
	}
	else if (ft_strcmp("setenv", shell->cmd[0]) == 0)
	{
		ft_set_env(shell->cmd, shell);
		return (1);
	}
	else if (ft_strcmp("unsetenv", shell->cmd[0]) == 0)
	{
		ft_unset_env(shell->cmd, shell);
		return (1);
	}
	else
		return (0);
}
