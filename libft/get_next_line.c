/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 17:55:14 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 15:40:12 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_join(char *buff, char *temp)
{
	size_t				i;
	size_t				j;
	char				*ptr;

	i = 0;
	j = 0;
	if (buff && temp)
		i = ft_strlen(buff);
	j = ft_strlen(temp);
	if (!(ptr = ft_strnew(i + j)))
		return (NULL);
	ft_memcpy(ptr, buff, i);
	ft_memcpy(ptr + i, temp, j);
	free(buff);
	return (ptr);
}

static int				ft_check(char **buff, char **temp, char **line)
{
	char				*ptr;
	char				*end;
	int					co;

	if (!(*buff = ft_join(*buff, *temp)))
		return (0);
	end = ft_strchr(*buff, '\n');
	if (end != NULL)
	{
		*end = '\0';
		co = end - *buff;
	}
	else
		co = -1;
	if (co > -1)
	{
		*line = ft_strdup(*buff);
		ptr = *buff;
		*buff = ft_strdup(*buff + co + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

int						get_next_line(const int fd, char **line)
{
	static char			*buffer[BUFF_SIZE];
	char				*temp;
	int					r;
	int					ret;

	temp = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE < 1 || fd < 0 || (ret = read(fd, temp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, temp, BUFF_SIZE)) > 0)
	{
		r = ft_check(&buffer[fd], &temp, line);
		ft_strdel(&temp);
		if (r == 1)
			return (1);
		temp = ft_strnew(BUFF_SIZE);
	}
	if ((r = ft_check(&buffer[fd], &temp, line)))
		return (1);
	if (ft_strlen(buffer[fd]) > 0)
	{
		*line = ft_strdup(buffer[fd]);
		ft_strdel(&buffer[fd]);
		return (1);
	}
	return (0);
}
