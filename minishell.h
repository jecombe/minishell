/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 18:12:05 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:46:16 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#define READ_SIZE 4096
#include "libft/libft.h"

typedef struct s_minishell
{
	char **tab;
	char **cmd;
	char **env;
}			t_minishell;

void		path(t_minishell *shell, char **env);
void		aff_prompt(char **argv, t_minishell *shell);
int		ft_builtin(char *cmd, t_minishell *shell);
char		**ft_str_cmd(char *cmd, t_minishell *shell);
int			ft_count(char *str, int value);
int			ft_count_char(char *str);
void			sigint(int sig);
void		ft_fork(t_minishell *shell);
void		ft_putstr_color(const char *str, int nb);

#endif
