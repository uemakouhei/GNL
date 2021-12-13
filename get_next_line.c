#include "get_next_line.h"
static char     *safely_return(t_fd_info *info,char **line)
{
	puts("in safly");
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
	if (info -> buf == NULL || info -> index >= info -> read_bytes)
	{
		free(info->buf);
		info->buf = (char *)ft_calloc(sizeof(char),BUFFER_SIZE);
		if (info->buf == NULL)
			return (ERR);
		info->read_bytes = read(fd, info->buf, BUFFER_SIZE);
		printf("read.buf = %s\n",info -> buf);
		if (info->read_bytes < 0)
			return (ERR);
		if (info->read_bytes == 0)
			return (EndofFile);
		info->index = 0;
	}
	else 
		info -> index++;
	return (1);
}
ssize_t ft_memcat(char **line,t_fd_info *info,size_t size)
{
	static void *ptr;
	if (*line == NULL)
		size = INITIAL_ALLOCATE_SIZE;
	else 
		size *= 2;	
	ptr = malloc(sizeof(char) * size);
	if (ptr == NULL)
		info -> sign = ERR;
	*line = (char *)ptr;
	return (size);
}
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
		{
			mallocsize = 256;
			//mallocsize = ft_memcat(&line,&fd_info,mallocsize);
			line = (char *)malloc(sizeof(char) * 256);
		}
		line[i] = fd_info.buf[fd_info.index];
		printf("index %ld : %c\n",i,line[i]);
		if (line[i++] == '\n')
		{
			printf("(%s)\n",line);
			//printf("return : %s\n",line);
			return (line);
		}
	}
	return(safely_return(&fd_info,&line));
}
