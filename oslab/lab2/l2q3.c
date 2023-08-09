#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
char str[100][100];
char temp[100];
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
		strcpy(str[i],entry->d_name);
		i++;
	}

	for(int l=0;l<=i;l++) {
     	for(int j=l+1;j<=i;j++) {
        	if(strcmp(str[l],str[j])>0) {
	            strcpy(temp,str[l]);
	            strcpy(str[l],str[j]);
	            strcpy(str[j],temp);
        	}
      	}
  	}

   	for(int x=0;x<=i;x++) {
      	puts(str[x]);
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