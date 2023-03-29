#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char buf[100];
	int fd[2];
	pipe(fd);

	if(fork()==0){
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		printf("%s from child process\n",buf);
		exit(0);
	}
	else
	{
		close(fd[0]);
		printf("hello from parent process\n");
		write(fd[1],"hello",6);
		wait(NULL);
		return 0;
	}
}
