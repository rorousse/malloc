/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 09:15:11 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/04 14:58:40 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include <time.h>

static int		ft_inf_strcat(char **dst, char *src, int ret_read)
{
	char			*temp;

	if ((temp = ft_strnew(ft_strlen(*dst) + 1)) == NULL)
		return (-1);
	ft_strcpy(temp, *dst);
	free(*dst);
	if ((*dst = ft_strnew(ft_strlen(temp) + ret_read + 1)) == NULL)
		return (-1);
	ft_strcpy(*dst, temp);
	*dst = ft_strncat(*dst, src, ret_read);
	if (ft_strchr(*dst, '\n') != NULL)
		*(ft_strchr(*dst, '\n')) = '\0';
	free(temp);
	return (0);
}

static int		ft_load_buff(char *buffer, char **line)
{
	if (ft_strchr(buffer, '\n') != NULL)
	{
		if (ft_inf_strcat(line, ft_strchr(buffer, '\n') + 1,
		ft_strlen(buffer)) == -1)
			return (-1);
		ft_strpushback(buffer, (int)((ft_strchr(buffer, '\n') - buffer) + 1));
	}
	if (ft_strchr(buffer, '\n') != NULL)
		return (1);
	return (0);
}

static t_buffer	*new_buff(t_buffer *buff, int fd)
{
	t_buffer *new;

	if (!(new = (t_buffer*)malloc(sizeof(t_buffer))))
		return (NULL);
	new->data = (char*)malloc((BUFF_SIZE + 1) * sizeof(char));
	new->fd = fd;
	new->init = ft_strdup("initialized\n");
	new->prev = buff;
	new->next = NULL;
	return (new);
}

static int		ft_init_buff(t_buffer **buff, int fd)
{
	if (*buff == NULL)
	{
		*buff = new_buff(NULL, fd);
	}
	else
	{
		while ((*buff)->prev != NULL)
			*buff = (*buff)->prev;
		while ((*buff)->next != NULL && (*buff)->fd != fd)
			*buff = (*buff)->next;
		if ((*buff)->fd != fd)
		{
			(*buff)->next = new_buff(*buff, fd);
			if ((*buff)->next == NULL)
				return (-1);
			*buff = (*buff)->next;
		}
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_buffer	*buffer = NULL;
	int				ret_read;
	char			*ret_chr;

	if (line == NULL || fd < 0 || ft_init_buff(&buffer, fd) == -1)
		return (-1);
	*line = ft_strdup("\0");
	if ((ret_read = ft_load_buff(buffer->data, line)) != 0)
		return (ret_read);
	ret_chr = NULL;
	ret_read = 1;
	while (ret_chr == NULL && ret_read > 0)
	{
		if ((ret_read = read(fd, buffer->data, BUFF_SIZE)) == -1)
			return (-1);
		buffer->data[ret_read] = '\0';
		ret_chr = ft_strchr(buffer->data, '\n');
		if (ft_inf_strcat(line, buffer->data, ret_read) == -1)
			return (-1);
	}
	if (ft_strcmp(*line, "\0") != 0)
		return (1);
	if (ret_read > 0)
		return (1);
	return (ret_read);
}
