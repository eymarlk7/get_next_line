/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eymarplayboy7 <eymarplayboy7@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:01:12 by pcapalan          #+#    #+#             */
/*   Updated: 2025/02/01 17:25:55 by eymarplaybo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *allocate_or_resize_buffer(char *line, size_t *line_size)
{
	size_t i;
    size_t new_size;
	char *new_line;
	
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

char *get_next_line(int fd)
{
    static char str[BUFFER_SIZE];
    static t_counts counts = {0, 0};
    char *line; 
    t_itr itr;
    
    ft_init_iterators(&itr);
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0) 
		return (NULL);
    while (1)
    {
        if (counts.posix_current >= counts.bytes_read)
            if (read_buffer(fd, str, &counts.bytes_read, &counts.posix_current) <= 0)
                break;
        if (itr.i >= itr.line_size)
            line = allocate_or_resize_buffer(line, &itr.line_size);
        line[itr.i++] = str[counts.posix_current++];
        if (line[itr.i - 1] == '\n')
            break;
    }
    if (itr.i == 0)
        return (free(line), NULL);
    line[itr.i] = '\0';
    return (line);
}

int main(int argc, char const *argv[])
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
	char *line;
	while ((line = get_next_line(fd) )!= NULL)
    {
		printf("line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}