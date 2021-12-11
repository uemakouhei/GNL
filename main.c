#include "get_next_line.h"
#include <fcntl.h>
int main(void)
{
	int fd;

	fd = open("./test_txt", O_RDONLY);
	char *s;

	s = get_next_line(fd);
	printf("%s",s);
}
