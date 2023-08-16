#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	int status;
	pid_t pid;
	pid = fork();
	if(pid == -1)
		printf("\nERROR child not created");
	else if (pid == 0) {
		printf("\nI'm the child!\n");
		for(int i=0;i<5;i++){
			printf("Child is printing\n");
		}
		exit(0);
	}
	else {
		wait(&status);
		printf("\nI'm the parent!");
		printf("\nChild returned: %d\n", status);
	}
}
