#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
int main() {
	pid_t pid;
	char *message;
	int n,x;
	printf("fork program starting\n");
	pid = fork();
	switch(pid) {
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is the child";
			x=getpid();
			n = 2;
			break;
		default:
			message = "This is the parent";
			x=getpid();
			n = 10;
			break;
	}
	for(n; n > 0; n--) {
		puts(message);
		printf("PID:%d\n",x);
		sleep(1);
	}
	exit(0);
}