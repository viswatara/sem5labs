#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
char reply[1];
void printdir(char *dir, int depth) {
	int i=0;
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp = opendir(dir)) == NULL) {
		fprintf(stderr,"cannot open directory: %s\n", dir);
		return; }

	chdir(dir);

	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name,&statbuf);
		if(strcmp(".",entry->d_name) == 0 ||strcmp("..",entry->d_name) == 0)
				continue;
		else {
			printf("Remove %s ? Y | N\n", entry->d_name);
			scanf("%s", reply);
			if(strcmp("y",reply)==0){
				remove(entry->d_name);
			}
			else {
				continue;
			}
		}

	}

	chdir("..");
	closedir(dp);
	
}

int main(){
	char dir[100];
	printf("Enter name\n");
	scanf("%s",dir);
	printdir(dir,0);
}