#include "get_next_line.h"
#include <fcntl.h>
int main(void)
{
	int fd,i;
	int count = TEST_COUNT;

	i = 0;
	fd = open("./test.txt", O_RDONLY); 
	while (count != 0)
	{
		printf("line %d : %s\n",i,get_next_line(fd));
		count--;
		i++;
	}
	return (0);
}
