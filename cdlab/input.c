/in.c
#include<stdio.h>
//print array
void printArraylist(int array[],int size){
for(int i=o;i<size;i++)
{printf("%d",,array[i]);
}
printf("\n");
}

int main()
{
int data[]={2,45,0,11,9};

//fund the array's length
int size= sizeof(data)/sizeof(data[0]);
printf("entered array    :\n ");
printArray(data,size);
}
