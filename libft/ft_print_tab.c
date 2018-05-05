/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_tab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 15:37:38 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 15:38:48 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_tab(char **tab, int value)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (value == 1)
		{
			ft_putstr_color("::", 6);
			ft_putstr(STOP);
		}
		ft_putendl(tab[i]);
		i++;
	}
}
