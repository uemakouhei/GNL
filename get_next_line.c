#include "get_next_line.h"
static char     *safely_return(t_fd_info *info,char **line)
{
	free(info -> buf);
	if (info -> sign == EOF)
	{
		*line = (char *)malloc(info -> read_bytes);
		*line = (char *)ft_memcpy(*line,info -> buf,info -> read_bytes);
		info -> buf = NULL;
		return(*line);
	}
	return(NULL);
}

static ssize_t fd_read_str(t_fd_info *info,int fd)
{

	info->buf = (char *)malloc(BUFFER_SIZE);
	if (info->buf == NULL)
		info -> sign = ERR;
	info->read_bytes = read(fd, info->buf, BUFFER_SIZE);
	if (info->read_bytes < 0)
		info -> sign = ERR;
	if (info->read_bytes == 0)
		info -> sign = EOF;
	return (1);
}
ssize_t ft_memcat(char **line,t_fd_info *info,size_t size)
{
	void *ptr;
	if (*line == NULL)
		*line = (char *)malloc(size);
	else 
	{
		ptr = malloc(size * 2);
		if (ptr == NULL)
		{
			info -> sign = ERR;
			return (ERR);
		}
		ptr = ft_memcpy(ptr,line,size);
		size *= 2;
	}
	return (size);
}
char    *get_next_line(int fd)
{
	char *line;
	static t_fd_info fd_info; 
	ssize_t mallocsize;
	size_t i;

	i = 0;
	mallocsize = 0;
	fd_info = (struct s_fd_info){ 0 };
	line = NULL;
	if (fd_info.buf == NULL)
		fd_read_str(&fd_info,fd);
	while (fd_info.sign == 0 || fd_info.index >= fd_info.read_bytes)
	{
		if (mallocsize <= fd_info.index)
			mallocsize = ft_memcat(&line,&fd_info,mallocsize);
		*line = fd_info.buf[fd_info.index];
		if (*line == '\n')
			return (line);
		fd_info.index++;
		line++;
	}
	return(safely_return(&fd_info,&line));
}


