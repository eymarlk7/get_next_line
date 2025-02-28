/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:51:42 by pcapalan          #+#    #+#             */
/*   Updated: 2025/02/28 16:58:57 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_itr
{
	size_t	i;
	size_t	line_size;
}	t_itr;

typedef struct s_counts
{
	size_t	b_read;
	size_t	pos_cur;
}	t_cnts;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_init_iterators(t_itr *itr);
char	*allocate_or_resize_buffer(char *line, size_t *line_size);
size_t	read_buffer(int fd, char *buffer, size_t *b_read, size_t *pos_cur);

#endif
