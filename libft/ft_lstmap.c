/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecombe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:56:22 by jecombe           #+#    #+#             */
/*   Updated: 2017/11/20 17:27:12 by jecombe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list		*temp;

	if (!lst)
		return (NULL);
	else
	{
		temp = (t_list*)malloc(sizeof(lst));
		if (temp == NULL)
			return (NULL);
		temp = f(lst);
		temp->next = ft_lstmap(lst->next, f);
		return (temp);
	}
}
