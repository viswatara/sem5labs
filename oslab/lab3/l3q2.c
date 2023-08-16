#include<sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
	pid_t pid;
	pid = fork();
	if (pid < 0) { 
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { 
		execlp("./l3q1", "l3q1", NULL);
		
	}
	else { 
		wait (NULL);
		printf ("Child Complete");
		exit(0);
	}
}