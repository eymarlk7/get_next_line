/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eymarplayboy7 <eymarplayboy7@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:00:50 by pcapalan          #+#    #+#             */
/*   Updated: 2025/02/01 17:20:48 by eymarplaybo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_init_iterators(t_itr *itr)
{
	itr->i = 0;
	itr->line_size = 0;
}

size_t ft_strlen(const char *str)
{
	size_t i;

	i = -1;
	while (str[++i]);
	return (i);
}

size_t read_buffer(int fd, char *buffer, size_t *bytes_read, size_t *posix_current)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read == -1)
		return (0);
	*posix_current = 0;
	return (*bytes_read);
}
