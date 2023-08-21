#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
typedef struct Token {
    int row_no;
    int col_no;
    char type[256];
} Token;

int ind = 0;

char keywords[32][10]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long"
    ,"return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while","restrict"};

int ArithOp(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

int LogicalOp(char c) {
    if(c == '!' || c == '&' || c == '|') {
        return 1;
    }
    return 0;
}

int RelOp(char c) {
    if(c == '>' || c == '<' || c == '=' || c == '!') {
        return 1;
    }
    return 0;
}

int isStringLiteral(char line[],int i,int *start_ind) {
    int end_ind = i;
    if(line[end_ind] == '"') {
        (*start_ind) = end_ind;
        end_ind++;
        while(line[end_ind] != '"') {
            end_ind++;
        }
    }
    return end_ind;
}

void createToken(Token token[256],int row_no,int col_no,char *str) {
    strcpy(token[ind].type,str);
    token[ind].row_no = row_no;
    token[ind].col_no = col_no;
    ind++;
}

void getArithOp(char line[],int row_no,Token token[256]) {
    for(int i=0;i<strlen(line);i++) {
        int x = 0;
        i = isStringLiteral(line,i,&x);
        if(!ArithOp(line[i]))
            continue;
        if(ArithOp(line[i]) && !ArithOp(line[i+1]) && !ArithOp(line[i-1]) && (i+1)<strlen(line)) {
            if(line[i] == '+') {
                createToken(token,row_no,i,"ARTHOP: +");
            }
            else if(line[i] == '-') {
                createToken(token,row_no,i,"ARTHOP: -");
            }
            else if(line[i] == '*') {
                createToken(token,row_no,i,"ARTHOP: *");
            }
            else if(line[i] == '/') {
                createToken(token,row_no,i,"ARTHOP: /");
            }
        }
    }
}

void getLogicalOp(char line[],int row_no,Token token[256]) {
    for(int i=0;i<strlen(line);i++) {
        int x = 0;
        i = isStringLiteral(line,i,&x);
        if(!LogicalOp(line[i]))
            continue;
        if((i+1) < strlen(line)) {
            if(line[i] == '&' && line[i+1] == '&') {
                createToken(token,row_no,i,"LgOP: AND");
                i++;
            }
            else if(line[i] == '|' && line[i] == '|') {
                createToken(token,row_no,i,"LgOP: OR");
                i++;
            }
            else if(line[i] == '!' && !LogicalOp(line[i+1])) {
                createToken(token,row_no,i,"LgOP: NOT");
                i++;
            }
        }
    }
}

void getRelOp(char line[],int row_no,Token token[256]) {
    for(int i=0;i<strlen(line);i++) {
        int x = 0;
        i = isStringLiteral(line,i,&x);
        if(!RelOp(line[i]))
            continue;
        if((i+1) < strlen(line)) {
            if(line[i] == '!' && line[i+1] == '=') {
                createToken(token,row_no,i,"Relop:NE");
                i++;
            }
            else if(line[i] == '=' && line[i+1] == '=') {
                createToken(token,row_no,i,"Relop:EQ");
                i++;
            }
            else if(line[i] == '<' && line[i+1] == '=') {
                createToken(token,row_no,i,"Relop:LE");
                i++;
            }
            else if(line[i] == '>' && line[i+1] == '=') {
                createToken(token,row_no,i,"Relop:GE");
                i++;
            }
            else if(line[i] == '<' && !RelOp(line[i+1])) {
                createToken(token,row_no,i,"Relop:LT");
                i++;
            }
            else if(line[i] == '>' && !RelOp(line[i+1])) {
                createToken(token,row_no,i,"Relop:GT");
                i++;
            }
        }
    }
}

void getStringLiteral(char line[],int row_no,Token token[256]) {
    for(int i=0;i<strlen(line);i++) {
        int start_ind = 0;
        int end_ind = isStringLiteral(line,i,&start_ind);
        if(i == end_ind)
            continue;
        char literal[256];
        int k = 0;
        for(int j=start_ind;j<=end_ind;j++) {
            literal[k++] = line[j];
        }
        literal[k] = '\0';
        char str[256] = {"LITERAL : "};
        strcat(str,literal);
        createToken(token,row_no,i,str);
        i = end_ind;
    }
}




void sortTokens(Token *token) {
    for(int i = 0; i < ind-1; i++) {
        for(int j = 0; j < ind-i-1; j++) {
            if(token[j].row_no == token[j + 1].row_no) {
                if(token[j].col_no > token[j + 1].col_no) {
                    Token temp = token[j];
                    token[j] = token[j + 1];
                    token[j + 1] = temp;
                }
            }
        }
    }
}


int isKeyword(char *str) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isIdentifierChar(char c) {
    return isalpha(c) || isdigit(c) || c == '_';
}

void getIdentifiers(char line[], int row_no, Token token[256]) {
    int i = 0;
    while (i < strlen(line)) {
        int x = 0;
        i = isStringLiteral(line, i, &x);
        
        if (!isIdentifierChar(line[i])) {
            i++;
            continue;
        }

        int start_ind = i;
        while (isIdentifierChar(line[i])) {
            i++;
        }
        
        int end_ind = i - 1;

        int identifierLength = end_ind - start_ind + 1;
        char identifier[identifierLength + 1];
        strncpy(identifier, line + start_ind, identifierLength);
        identifier[identifierLength] = '\0';
        if (!isKeyword(identifier)) {
            char str[256] = {"ID : "};
            strcat(str,identifier);
            createToken(token, row_no, start_ind,str);
        }
    }
}

int isNumCon(char c) {
    return  isdigit(c);
}

void getNumCon(char line[], int row_no, Token token[256]) {
    int i = 0;
    while (i < strlen(line)) {
        int x = 0;
        i = isStringLiteral(line, i, &x);
        
        if (!isNumCon(line[i])) {
            i++;
            continue;
        }

        int start_ind = i;
        while (isNumCon(line[i])) {
            i++;
        }
        
        int end_ind = i - 1;

        int numConLength = end_ind - start_ind + 1;
        char numCon[numConLength + 1];
        strncpy(numCon, line + start_ind, numConLength);
        numCon[numConLength] = '\0';
        char str[256] = {"NumCon : "};
        strcat(str,numCon);
        createToken(token, row_no, start_ind,str);
    }
}


void getKeywords(char line[], int row_no, Token token[256]) {
    int i = 0;
    while (i < strlen(line)) {
        int x = 0;
        i = isStringLiteral(line, i, &x);
        
        if (!isalpha(line[i])) {
            i++;
            continue;
        }

        int start_ind = i;
        while (isIdentifierChar(line[i])) {
            i++;
        }
        
        int end_ind = i - 1;

        int keywordLength = end_ind - start_ind + 1;
        char keyword[keywordLength + 1];
        strncpy(keyword, line + start_ind, keywordLength);
        keyword[keywordLength] = '\0';
        char str[256] = {"KW : "};
        strcat(str,keyword);
        if (isKeyword(keyword)) {
            createToken(token, row_no, start_ind,str);
        }
    }
}
void getSpclSym(char line[],int row_no,Token token[256]) {
    for(int i=0;i<strlen(line);i++) {
        int x = 0;
        i = isStringLiteral(line,i,&x);
        if((i+1) < strlen(line)) {
            if(line[i] == '$') {
                createToken(token,row_no,i,"SpclSym: $");
                i++;
            }
            else if(line[i] == '%') {
                createToken(token,row_no,i,"SpclSym: %");
                i++;
            }
            else if(line[i] == '&') {
                createToken(token,row_no,i,"SpclSym: &");
                i++;
            }
            else if(line[i] == '\\') {
                createToken(token,row_no,i,"SpclSym: \\");
                i++;
            }
            else if(line[i] == '/') {
                createToken(token,row_no,i,"SpclSym: /");
                i++;
            }
            else if(line[i] == ';') {
                createToken(token,row_no,i,"SpclSym: ;");
                i++;
            }
            else if(line[i] == '?') {
                createToken(token,row_no,i,"SpclSym: ?");
                i++;
            }
            else if(line[i] == ')') {
                createToken(token,row_no,i,"SpclSym: )");
                i++;
            }
            else if(line[i] == '(') {
                createToken(token,row_no,i,"SpclSym: (");
                i++;
            }
            else if(line[i] == '{') {
                createToken(token,row_no,i,"SpclSym: {");
                i++;
            }
            else if(line[i] == '}') {
                createToken(token,row_no,i,"SpclSym: }");
                i++;
            }
            else if(line[i] == '[') {
                createToken(token,row_no,i,"SpclSym: [");
                i++;
            }
            else if(line[i] == ']')
            {
                createToken(token,row_no,i,"SpclSym: ]");
                i++;
            }
            else if(line[i] == '^')
            {
                createToken(token,row_no,i,"SpclSym: ^");
                i++;
            }
            else if(line[i] == '#') {
                createToken(token,row_no,i,"SpclSym: #");
                i++;
            }
            else if(line[i] == '.') {
                createToken(token,row_no,i,"SpclSym: .");
                i++;
            }
            else if(line[i] == ':') {
                createToken(token,row_no,i,"SpclSym: :");
                i++;
            }
            else if(line[i] == '~') {
                createToken(token,row_no,i,"SpclSym: ~");
                i++;
            }
            else if(line[i] == '`') {
                createToken(token,row_no,i,"SpclSym: `");
                i++;
            }
        }
    }
}


int main()
{
    Token token[256];
    char line[256];
    int row_no = 1;
    FILE *fa,*fb;
    int ca;
    fa = fopen("acha1.c", "r");
    if(fa == NULL)
    {
        printf("\nCan't open file, try again :)");
        exit(0);
    }
    fb = fopen("acha2.c", "w");
    ca = getc(fa);
    while (ca != EOF)
    {
        if (ca=='/') {
            ca = getc(fa);
            if (ca == '/') {
                while(ca != '\n')
                    ca = getc(fa);
            }
            else if (ca == '*') {
                do {
                    while(ca != '*')
                        ca = getc(fa);
                    ca = getc(fa);
                } while (ca != '/');
            }
            else {
                putc(ca,fb);
            }
        }
        if (ca=='"') {
            putc(ca,fb);
            ca = getc(fa);
                while(ca!='"') {
                    putc(ca,fb);
                    ca = getc(fa);
                }
        }
        if (ca=='\'') {
            putc(ca,fb);
            ca = getc(fa);
                while(ca!='\'') {
                    putc(ca,fb);
                    ca = getc(fa);
                }
        }
        if(ca=='#') {   
            while(ca!='\n') {
                ca = getc(fa);
            }
        }   
        else putc(ca,fb);
        ca = getc(fa);
        
    }
    fclose(fa);
    fclose(fb);
    fa = fopen("acha2.c", "r");
    if(fa == NULL) {
        printf("\nCan't open file, try again :)");
        exit(0);
    }
   
    while(fgets(line,256,fa)) {
        getArithOp(line,row_no,token);
        getLogicalOp(line,row_no,token);
        getRelOp(line,row_no,token);
        getStringLiteral(line,row_no,token);
        getIdentifiers(line,row_no,token);
        getKeywords(line,row_no,token);
        getSpclSym(line,row_no,token);
        getNumCon(line,row_no,token);
        row_no++;
    }
    sortTokens(token);
    for(int i = 0; i < ind; i++) {
        printf("\n<%s, %d, %d>",token[i].type,token[i].row_no,token[i].col_no);
    }
    fclose(fa);
    return 0;
}
