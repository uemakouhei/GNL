#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef INITIAL_ALLOCATE_SIZE
#  define INITIAL_ALLOCATE_SIZE 8
# endif

# define ERR -1
# define EOF -2

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_info
{
        char    *buf;
        ssize_t index;
	ssize_t read_bytes;
	int sign;
}       t_fd_info;
void    *ft_memcpy(void *dst, const void *src, size_t n);
char    *get_next_line(int fd);
#endif

