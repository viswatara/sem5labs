#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fptr1, *fptr2;
	char filename[100],c;
	printf("Enter name of file to reverse\n");
	scanf("%s",filename);
	fptr1=fopen(filename, "r");
	if(fptr1==NULL){
		printf("Nothing here!");
		exit(0);
	}
	printf("Enter file name to write reverse to");
	scanf("%s", filename);
	fptr2=fopen(filename,"w+");
	fseek(fptr1,0,SEEK_END);
	int filesize=ftell(fptr1);
	fseek(fptr1,0,SEEK_SET);
	printf("Size of file is: %d\n", filesize);
	int endpos=filesize-1;
	while(endpos>=0){
		fseek(fptr1, endpos, SEEK_SET);
		c=fgetc(fptr1);
		fputc(c,fptr2);
		endpos--;
	}
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
