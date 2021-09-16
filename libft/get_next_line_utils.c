/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:49:20 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/31 16:11:26 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_progress	*progress_get(t_progress **progresses, int fd, char **buf)
{
	t_progress	*cur;

	*buf = 0;
	if (!*progresses)
	{
		*progresses = ft_calloc(sizeof(t_progress), 1);
		if (!*progresses)
			return (0);
		(*progresses)->fd = fd;
		return (*progresses);
	}
	cur = *progresses;
	while (cur->next)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	if (cur->fd == fd)
		return (cur);
	cur->next = ft_calloc(sizeof(t_progress), 1);
	if (!(cur->next))
		return (0);
	cur->next->fd = fd;
	return (cur->next);
}

void	progress_remove(t_progress **progresses, int fd)
{
	t_progress	*cur;
	t_progress	*next;

	cur = *progresses;
	if (cur && cur->fd == fd)
	{
		next = cur->next;
		if (cur->save)
			free(cur->save);
		free(cur);
		*progresses = next;
		return ;
	}
	while (cur && cur->next)
	{
		if (cur->next->fd == fd)
		{
			next = cur->next->next;
			if (cur->next->save)
				free(cur->next->save);
			free(cur->next);
			cur->next = next;
		}
		cur = cur->next;
	}
}

char	*ft_findany(const char *str, const char *src, size_t max_len)
{
	size_t	i;
	size_t	j;

	if (!str || !src)
		return (0);
	i = 0;
	while (str[i] && i < max_len)
	{
		j = 0;
		while (src[j])
			if (str[i] == src[j++])
				return ((char *)str + i);
		i++;
	}
	return (0);
}
