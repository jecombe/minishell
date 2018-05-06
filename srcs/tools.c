/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 12:57:55 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 15:15:52 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		init_shell(void)
{
	ft_putstr("\e[95m");
	ft_putendl("__  __ _____ _   _ _____  _____ _    _ ______ _      _");
	ft_putendl("|  \\/  |_   _| \\ | |_   _|/ ____| |  | |  ____| |    | |");
	ft_putendl("| \\  / | | | |  \\| | | | | (___ | |__| | |__  | |    | |");
	ft_putendl("| |\\/| | | | | . ` | | |  \\___ \\|  __  |  __| | |    | |");
	ft_putendl("| |  | |_| |_| |\\  |_| |_ ____) | |  | | |____| |____| |____");
	ft_putendl("|_|  |_|_____|_| \\_|_____|_____/|_|  |_|______|______|______|\
			");
	ft_putstr("\e[39m");
	ft_putstr("\n");
}

void		ft_print_prompt(void)
{
	ft_putchar('\r');
	ft_putstr_color("[", 10);
	ft_putstr(STOP);
	ft_putstr_color(g_user, 14);
	ft_putstr(STOP);
	ft_putstr_color("]", 10);
	ft_putstr(STOP);
	ft_putstr_color("==> ", 9);
	ft_putstr(STOP);
}

void		ft_print_error(const char *s1, const char *s2)
{
	ft_putstr_color(s1, 3);
	ft_putstr(STOP);
	ft_putstr_color(s2, 1);
	ft_putstr(STOP);
	ft_putstr("\n");
}

void		sigint(int sig)
{
	(void)sig;
	ft_putchar('\n');
	ft_print_prompt();
}

int			ft_check_space(char *buff)
{
	int i;
	int ok = 0;

	i = 0;
	/*while (buff[i])
	{
		if (buff[i] > 32 && buff[i] < 127)
		{
			ok++;
		}
		i++;
	}
	if (ok > 0)
		return (1);
	else
		return (0);*/
	if (buff[i] == '\n')
		return (0);
	while (buff[i] == ' ' && buff[i + 1] != '\n')
		i++;
	if (buff[i + 1] == '\n')
		return (0);
	else
		return (1);
}
