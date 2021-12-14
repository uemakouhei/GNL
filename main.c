#include "get_next_line_bonus.h"
#include<fcntl.h>
int main(void)
{
	int fd1,fd2,fd3;	
	fd1 = open("./test1", O_RDONLY); 
	fd2 = open("./test2", O_RDONLY);
	fd3 = open("./test3", O_RDONLY);	
	printf("fd3 : %s\n",get_next_line(fd3));
	printf("fd1 : %s\n",get_next_line(fd1));
	printf("fd3 : %s\n",get_next_line(fd3));
	printf("fd1 : %s\n",get_next_line(fd1));
	 printf("fd3 : %s\n",get_next_line(fd3));
	 printf("fd3 : %s\n",get_next_line(fd3));
	 printf("fd2 : %s\n",get_next_line(fd2));
}
