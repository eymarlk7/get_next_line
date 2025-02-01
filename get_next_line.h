#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

typedef struct s_itr
{
    size_t i;
    size_t line_size;
} t_itr;

typedef struct s_counts
{
    size_t bytes_read;
    size_t posix_current;
    t_itr itr;
} t_counts;

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
void ft_init_iterators(t_itr *itr);
char *allocate_or_resize_buffer(char *line, size_t *line_size);
size_t read_buffer(int fd, char *buffer, size_t *bytes_read, size_t *posix_current);

#endif
