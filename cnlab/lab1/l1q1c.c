#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
int main(){
	int len, result, sockfd, n=1;
	struct sockaddr_in address;
	char ch[256], buf[256];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("172.16.59.15");
	address.sin_port=htons(10215);
	len=sizeof(address);
	result=connect(sockfd,(struct sockaddr*)&address,len);
	if(result==-1){
		perror("\nCLIENT ERROR");
		exit(1);
	}
	printf("\nEnter String:\t");
	gets(ch);
	ch[strlen(ch)]='\0';
	for(int i=0;i<strlen(ch);i++){
		ch[i]=ch[i]+4;
	}
	write(sockfd,ch,strlen(ch));
	
}
