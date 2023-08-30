#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 7
int main() {
	int pipe_fd;
	int res;
	int open_mode = O_RDONLY;
	char buffer[BUFFER_SIZE];
	int bytes_read = 0;
	memset(buffer, '\0', sizeof(buffer));
	printf("Process %d opening FIFO O_RDONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);
	printf("Process %d result %d\n", getpid(), pipe_fd);
	if (pipe_fd != -1) {
			
			res = read(pipe_fd, buffer,4);
			printf("%s ",buffer);

		
		(void)close(pipe_fd);
	}
	else {
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished", getpid());
	exit(EXIT_SUCCESS);
}