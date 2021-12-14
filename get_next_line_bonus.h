#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# ifndef INITIAL_ALLOCATE_SIZE
#  define INITIAL_ALLOCATE_SIZE 100
# endif
	
# ifndef TEST_COUNT
#  define TEST_COUNT 5
# endif
# define ERR -1
# define EndofFile -2

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
typedef struct s_fd_info
{
        char    *buf;
        ssize_t index;
	ssize_t read_bytes;
	int sign;
	int save_fd;
}       t_fd_info;
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_calloc(size_t count, size_t size);
char    *get_next_line(int fd);
#endif

