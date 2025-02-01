#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char str[BUFFER_SIZE];
    static t_counts counts = {0, 0};
    char *line;
    t_itr itr;

    line = NULL;
    ft_init_iterators(&itr);
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
