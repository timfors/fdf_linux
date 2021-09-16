/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bojamee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:19 by bojamee           #+#    #+#             */
/*   Updated: 2021/09/02 13:21:21 by bojamee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define	GET_NEXT_LINE_H
# define	BUFFER_SIZE 4096

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int			get_next_line(int fd, char **line);
char		*ft_findany(const char *str, const char *c, size_t max_len);

typedef struct s_progress
{
	int					fd;
	struct s_progress	*next;
	char				*save;
}			t_progress;

int			parse_fd(int fd, char **buf, t_progress *progress, char **line);
int			check_save(t_progress *progress, char **res);
int			check_buffer(t_progress *progress, char *buf, int len, char **res);
t_progress	*progress_get(t_progress **progresses, int fd, char **buf);
void		progress_remove(t_progress **progresses, int fd);
#endif
