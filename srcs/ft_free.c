/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 14:39:20 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 15:49:27 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_free(char **tab, char **env, char **cmd)
{
	ft_free_tab(tab);
	ft_free_tab(env);
	ft_free_tab(cmd);
}
