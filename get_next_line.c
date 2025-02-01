/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:56:47 by pcapalan          #+#    #+#             */
/*   Updated: 2025/02/01 18:19:58 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char			str[BUFFER_SIZE];
	char				*line;
	static t_count		cnts = {0, 0};
	t_itr				itr;

	line = NULL;
	ft_init_iterators(&itr);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (cnts.pos_cur >= cnts.b_read)
			if (read_buffer(fd, str, &cnts.b_read, &cnts.pos_cur) <= 0)
				break ;
		if (itr.i >= itr.line_size)
			line = allocate_or_resize_buffer(line, &itr.line_size);
		line[itr.i++] = str[cnts.pos_cur++];
		if (line[itr.i - 1] == '\n')
			break ;
	}
	if (itr.i == 0)
		return (free(line), NULL);
	line[itr.i] = '\0';
	return (line);
}
