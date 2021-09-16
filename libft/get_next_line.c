/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:46:27 by bojamee           #+#    #+#             */
/*   Updated: 2021/08/31 16:10:53 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_gnl_strjoin(const char *str1, const char *str2, size_t max_len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!str2 || !str1)
		return (0);
	j = max_len;
	if (ft_strlen(str2) < max_len)
		j = ft_strlen(str2);
	res = ft_calloc(ft_strlen(str1) + j + 1, 1);
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	while (j < max_len && str2[j])
	{
		res[i + j] = str2[j];
		j++;
	}
	return (res);
}

int	get_next_line(int fd, char **line)
{
	static t_progress	*progresses = 0;
	t_progress			*fd_progress;
	int					res;
	char				*buf;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	fd_progress = progress_get(&progresses, fd, &buf);
	if (!fd_progress)
		return (-1);
	*line = ft_calloc(1, 1);
	if (!*line)
		return (-1);
	res = parse_fd(fd, &buf, fd_progress, line);
	if (buf)
		free(buf);
	if (res == 1)
		return (1);
	progress_remove(&progresses, fd);
	if (res == 0)
		return (0);
	if (*line)
		free(*line);
	*line = 0;
	return (res);
}

int	parse_fd(int fd, char **buf, t_progress *progress, char **line)
{
	int		res;
	int		len;
	char	*new_line;

	if (progress->save)
	{
		res = check_save(progress, line);
		if (res != 2)
			return (res);
		new_line = ft_gnl_strjoin(*line, progress->save, BUFFER_SIZE * 2);
		free(*line);
		free(progress->save);
		progress->save = 0;
		if (!new_line)
			return (-1);
		*line = new_line;
	}
	*buf = ft_calloc(BUFFER_SIZE + 1, 1);
	while (1)
	{
		len = read(fd, *buf, BUFFER_SIZE);
		res = check_buffer(progress, *buf, len, line);
		if (res != 2)
			return (res);
	}
}

int	check_buffer(t_progress *progress, char *buf, int len, char **res)
{
	char	*new_res;
	char	*ending;

	if (len < 0 || !len)
		return ((len < 0) * -1);
	ending = ft_findany(buf, "\n\3", len);
	if (ending)
		new_res = ft_gnl_strjoin(*res, buf, ending - buf);
	else
		new_res = ft_gnl_strjoin(*res, buf, len);
	if (!new_res)
		return (-1);
	free(*res);
	*res = new_res;
	if (ending && *ending == '\3')
		return (0);
	else if (ending && *ending == '\n')
	{
		if (ending - buf != len)
			progress->save = ft_gnl_strjoin("", ending + 1,
					len - (ending - buf) - 1);
		return (1);
	}
	return (2);
}

int	check_save(t_progress *progress, char **result)
{
	int		res_code;
	char	*ending;
	char	*new_save;

	ending = ft_findany(progress->save, "\3\n", BUFFER_SIZE * 2);
	res_code = 2;
	if (!ending)
		return (res_code);
	if (*ending == '\3')
		res_code = 0;
	else if (*ending == '\n')
		res_code = 1;
	new_save = ft_gnl_strjoin("", ending + 1, ft_strlen(ending) - 1);
	if (!new_save)
		return (-1);
	free(*result);
	*result = ft_gnl_strjoin("", progress->save, ending - progress->save);
	if (!*result)
	{
		free(new_save);
		return (-1);
	}
	free(progress->save);
	progress->save = new_save;
	return (res_code);
}
