#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fptr1;
	int numc, cc;
	numc=0;
	cc=0;
	char filename[100],c;
	printf("Enter filename to count lines and characters in:\n");
	scanf("%s",filename);
	fptr1=fopen(filename,"r");
	if(fptr1==NULL){
		printf("Nothing here!");
		exit(0);
	}
	c=fgetc(fptr1);
	while(c!=EOF){
		cc++;
		if(c=='\n'){
			numc++;
		}
		c=fgetc(fptr1);
	}
	printf("Number of lines is: %d\nNumber of characters is : %d\n", numc, cc);
	fclose(fptr1);
	return 0;
}
