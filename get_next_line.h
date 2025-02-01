/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eymarplayboy7 <eymarplayboy7@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:20:42 by pcapalan          #+#    #+#             */
/*   Updated: 2025/02/01 17:23:34 by eymarplaybo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_itr
{
    size_t    i;
    size_t    line_size;
}    t_itr;

typedef struct s_counts
{
    size_t    bytes_read;
    size_t    posix_current;
    t_itr     itr;
}	t_counts;   


char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
void	ft_init_iterators(t_itr *itr);
size_t  read_buffer(int fd, char *buffer, size_t *bytes_read, size_t *posix_current);

#endif
