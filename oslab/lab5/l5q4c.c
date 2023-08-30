#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF
int main() {
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    int stock;
    int bytes_read = 0;
    printf("Process %d opening FIFO O_RDONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);
    if (pipe_fd != -1) {
        while (1) {
            res = read(pipe_fd, &stock, 4);
            bytes_read += res;
            if (stock>=0) {
                int st = stock -1;
                res = write(pipe_fd, &st, 4);
                printf("Removed one item from the shelf; Stock: %d\n", st);
            }
        }
        (void)close(pipe_fd);
    }
    else {
        exit(EXIT_FAILURE);
    }
    printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
    exit(EXIT_SUCCESS);
}