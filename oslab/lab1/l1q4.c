#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char *argv[]) {
	int fd=open(argv[1],O_RDONLY);
	int fd1=open(argv[2],O_WRONLY);
	char ch[1];
		while(ch[0]!='\0'){
			read(fd,ch,1);
			write(fd,ch,1);
		}
		printf("\nDone");
	}