#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *fa, *fb;
    char ca;
    char cmp[100];
    char arr[32][10]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long"
    ,"return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while","restrict"};
    char name[100];
    int i;
    int flag;
    fa=fopen("acha1.c","r");
    if(fa==NULL){
        printf("File not found");
        exit(1);
    }
    fb=fopen("acha2.c","w");
    ca=getc(fa);
    while(ca!=EOF){
            i=0;
            flag=0;
            while((ca>=65 && ca<=90) || (ca>=97 && ca<=122)){
                name[i]=ca;
                i++;
                ca=getc(fa);
            }
            name[i]='\0';
            if(i>0){
            for(int j=0;j<32;j++){
                if(strcmp(name,arr[j])==0){
                    flag=1;
                    for(int k=0;k<i;k++){
                        putc(toupper(name[k]),fb);
                    }
                }
            }
        }
            if(flag==0 && i>0){
                flag=1;
                    for(int k=0;k<i;k++){
                        putc(name[k],fb);
                    }
                    
            }
            else if(flag==0 && i==0){
                putc(ca,fb);
                ca=getc(fa);
            }
        }
    
    return 0;
}
    

	/*while (ca != EOF)
	{
		if(ca==' '||ca=='	'||ca=='+'||ca=='-'||ca==';'||ca=='*'||ca=='/'||ca==':'||ca=='('||ca==')'||ca=='{'||ca==']'||ca=='}'||ca=='['||ca=='='||ca=='&'
		||ca=='&'||ca=='%'||ca=='$'||ca=='#'||ca=='^'||ca=='\''||ca=='"'||ca=='.'||ca==','||ca=='?'||ca=='|'||ca=='<'||ca=='>'){
			if((strcmp(arr,"auto")==0)||(strcmp(arr,"break")==0)||(strcmp(arr,"case")==0)||(strcmp(arr,"char")==0)||(strcmp(arr,"const")==0)||
			   (strcmp(arr,"continue")==0)||(strcmp(arr,"default")==0)||(strcmp(arr,"do")==0)||(strcmp(arr,"double")==0)||(strcmp(arr,"else")==0)||
			   (strcmp(arr,"enum")==0)||(strcmp(arr,"extern")==0)||(strcmp(arr,"float")==0)||(strcmp(arr,"for")==0)||(strcmp(arr,"goto")==0)||
			   (strcmp(arr,"register")==0)||(strcmp(arr,"return")==0)||(strcmp(arr,"signed")==0)||(strcmp(arr,"short")==0)||(strcmp(arr,"sizeof")==0)||
			   (strcmp(arr,"if")==0)||(strcmp(arr,"int")==0)||(strcmp(arr,"long")==0)||(strcmp(arr,"static")==0)||(strcmp(arr,"struct")==0)||(strcmp(arr,"switch")==0)||
			   (strcmp(arr,"typedef")==0)||(strcmp(arr,"union")==0)||(strcmp(arr,"unsigned")==0)||(strcmp(arr,"void")==0)||(strcmp(arr,"volatile")==0)||
			   (strcmp(arr,"while")==0)) {
				for(int i=0;i<strlen(arr);i++){
					printf(" %c \n", toupper(arr[i]));
				}

				for(int i=0;i<strlen(arr);i++) {
					arr[i]='\0'; 
				}

				k=0;
				ca=getc(fa);
			}
			ca=getc(fa);
		}		
		arr[k++]=ca;
		ca=getc(fa);
	}
			
	fclose(fa);
	
	return 0;
	
}
*/
