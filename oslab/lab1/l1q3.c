#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char *argv[]) {
int a=2;
float b=1.2;
char c='x' ;
char d[10]="hellothere";
printf("a: %d, b:%f, c:%c, d: %s",a,b,c,d);
}
