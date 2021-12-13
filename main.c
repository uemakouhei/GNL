#include "get_next_line.h"
#include <fcntl.h>
int main(void)
{
	int fd;

	fd = open("./test.txt", O_RDONLY);
	char *s;

	s = get_next_line(fd);
	printf("1line :%s\n",s);
	s = get_next_line(fd);
	printf("2line : %s\n",s);
	s = get_next_line(fd);
	printf("3line : %s\n",s);
	s = get_next_line(fd);
	printf("4line : %s\n",s);
	s = get_next_line(fd);
	printf("5line : %s\n",s);

	//	printf("size,%ld : %s ",read(fd, &s, 1),s);
	//	printf("size,%ld : %s ",read(fd, &s, 1),s);
	//	printf("size,%ld : %s ",read(fd, &s, 1),s);
	//	printf("size,%ld : %s ",read(fd, &s, 1),s);

}
