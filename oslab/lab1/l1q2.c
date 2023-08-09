#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){
	int i;
	for(i=1;i<argc;i++){
		int lines=1;
		printf("%s\n",argv[i]);
		int fd=open(argv[i],O_RDONLY);
		char nread[1];
		while(lines<21){
			read(fd,nread,1);
			if(nread[0]=='\n'){
				lines++;
			}
			printf("%c",nread[0]);
		}

	}

}