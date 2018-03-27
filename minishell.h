/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 18:12:05 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 14:44:43 by jecombe     ###    #+. /#+    ###.fr     */
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
#define MAXCOM 1000
#define MAXLIST 100
#include "libft/libft.h"

typedef struct s_minishell
{
	char **tab;
	char **cmd;
	char **env;
}			t_minishell;
void		path(t_minishell *shell, char **env);
#endif
