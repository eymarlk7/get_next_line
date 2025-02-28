/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:53:14 by pcapalan          #+#    #+#             */
/*   Updated: 2025/02/01 18:06:15 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_init_iterators(t_itr *itr)
{
	itr->i = 0;
	itr->line_size = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

size_t	read_buffer(int fd, char *buffer, size_t *b_read, size_t *pos_cur)
{
	*b_read = read(fd, buffer, BUFFER_SIZE);
	if ((int)(*b_read) == -1)
		return (0);
	*pos_cur = 0;
	return (*b_read);
}

char	*allocate_or_resize_buffer(char *line, size_t *line_size)
{
	size_t	i;
	size_t	new_size;
	char	*new_line;

	if (*line_size == 0)
		new_size = BUFFER_SIZE;
	else
		new_size = (*line_size) * 2;
	new_line = (char *)malloc(new_size);
	if (!new_line)
		return (NULL);
	i = -1;
	while (++i < *line_size)
		new_line[i] = line[i];
	free(line);
	*line_size = new_size;
	return (new_line);
}
