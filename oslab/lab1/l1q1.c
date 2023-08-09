#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char *argv[]) {
	int fd;
	int i=0;
	int k=0;
	char ch[100];
	char chr;
	if(argc!=3) {
		printf("Insufficient arguments");
		exit(1);
	}
	fd=(open(argv[1],O_RDONLY));

	if(fd==-1)
	{
		printf("No file present");
		exit(1);
	}
	while((read(fd,&chr,1))>0) {
		i=0;
		if(chr!='\n') {
			ch[i]=chr;
			i++;
		}
		else{
			k++;
			ch[i]='\0';
			i=0;
			if(strstr(ch,argv[2])!=NULL) {
				printf("Line: %d\t %s\n",k,ch);
			}
		}
	}

}
