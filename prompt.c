/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:36 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 18:36:09 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_space(char *buff)
{
	int i;
	i = 0;
	while (buff[i] == ' ' || buff[i] == '\n')
		i++;
	if ((buff[i] >= 'a' && buff[i] <= 'z') || (buff[i] >= 'A' && buff[i] <= 'Z'))
		return (1);
	else
		return (0);
}

char		*ft_epure(char *str)
{
	int i;
	int j;

	if (!str)
		return(0);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			str[j] = str[i];
			j++;
			if (str[i + 1] ==  ' ' || str[i + 1] == '\t')
			{
				str[j] = ' ';
				j++;
			}
		}
	}
	str[j] = '\0';
	if (str[j - 1] == ' ')
		str[j - 1] = '\0';
	return (str);
}

void		aff_prompt(char **argv, t_minishell *shell)
{
	char *cmd;
	char *buff;
	int ret;
	int i = 0;
	(void)shell;
	(void)argv;

	cmd = (char *)malloc(sizeof(char) * (READ_SIZE));
	buff = (char *)malloc(sizeof(char) * (READ_SIZE));
	ft_putstr("🤠 $> ");
	if ((ret = (read(0, buff, READ_SIZE))) != -1)
	{
		if (ret == 0)
		{
			ft_putchar('\n');
			exit(0);
		}
		if (ft_check_space(buff) == 0)
			return;
		cmd = ft_epure(buff);
		shell->cmd = ft_str_cmd(cmd, shell);
		while (shell->env[i]!= NULL)
		{
			printf("=============> %s\n", shell->env[i]);
			i++;
		}
		if (ft_builtin(cmd, shell) == 1)
		{
		printf("-----> %s\n", cmd);
		return;
		}
		ft_fork(shell);
	}

}
