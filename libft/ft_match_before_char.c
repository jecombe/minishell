/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_match_before_cahr.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/22 13:31:55 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/22 16:22:38 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_match_before_char(char *cmd, char c, char *env)
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
