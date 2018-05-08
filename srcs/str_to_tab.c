/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_to_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 14:47:24 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 16:08:50 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

char			**ft_str_cmd_quote(char *cmd, t_minishell *shell)
{
	(void)shell;
	return (ft_split_quote(cmd));
}
