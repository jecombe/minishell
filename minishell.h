/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 18:12:05 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 18:15:29 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#ifndef MINISHELL_H
#define MINISHELL_H

typedef struct s_minishell
{
	char **tab;
	char **cmd;
	char **env;
}			t_minishell;
#endif
