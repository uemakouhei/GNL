#include "get_next_line.h"
static char     *safely_return(t_fd_info *info,char **line)
{
	free(info -> buf);
	if (info -> sign == EndofFile)
	{
		info -> buf = NULL;
		return(*line);
	}
	return(NULL);
}

static ssize_t fd_read_buf(t_fd_info *info,int fd)
{
	if (info -> buf == NULL || info -> index + 1 >= info -> read_bytes)
	{
		info->buf = (char *)ft_calloc(sizeof(char),BUFFER_SIZE);
		if (info->buf == NULL)
			return (ERR);
		info->read_bytes = read(fd, info->buf, BUFFER_SIZE);
		if (info->read_bytes < 0)
			return (ERR);
		if (info->read_bytes == 0)
			return (EndofFile);
		info->index = 0;
	}
	else  
		info -> index++;
	if (info -> sign != 0)
		return (0);
	return (1);
}

static ssize_t ft_memcat(char **line,ssize_t *mallocsize)
{
	void *ptr;

	ptr = NULL;
	if (*line == NULL)
	{
		*mallocsize = INITIAL_ALLOCATE_SIZE;
		*line = (char *)malloc(sizeof(char) * *mallocsize);
		if (*line == NULL)
			return (0);
	}
	else 
	{
		ptr = (char *)malloc(sizeof(char) * (*mallocsize * 2));
		if (ptr == NULL)
			return (0);
		ft_memcpy(ptr,*line,*mallocsize);
		*mallocsize *= 2;
		free(*line);
		*line = (char *)ptr;
	}
	return (1);
};
char    *get_next_line(int fd)
{
	char *line;
	static t_fd_info fd_info = {0};; 
	ssize_t mallocsize;
	ssize_t i;

	i = 0;
	mallocsize = 0;
	line = NULL;
	while (fd_read_buf(&fd_info,fd) == 1)
	{
		if (i + 1 >= mallocsize)
			if (!ft_memcat(&line,&mallocsize))
				return (NULL);
		line[i] = fd_info.buf[fd_info.index];
		if (line[i++] == '\n')
			return (line);
	}
	return(safely_return(&fd_info,&line));
};
