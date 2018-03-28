/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 17:53:36 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 15:46:02 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		aff_prompt(char **argv, t_minishell *shell)
{
	char *cmd;
	char *buff;
	int ret;
	(void)shell;
	(void)argv;

	cmd = (char *)malloc(sizeof(char) * (READ_SIZE));
	buff = (char *)malloc(sizeof(char) * (READ_SIZE));
	ft_putstr("$> ");
	if ((ret = (read(0, buff, READ_SIZE))) != -1)
	{
		printf("----%s\n", buff);
		if (ret == 0)
		{
			ft_putchar('\n');
			exit(0);
		}
		printf("-----> %s\n", cmd);
		/*if (ft_builtin(cmd, shell) == 1)
		return;*/
	}

}
