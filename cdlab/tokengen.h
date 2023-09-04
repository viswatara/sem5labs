typedef struct Token
{
    int index;
    int row_no;
    int col_no;
    char type[256];
    char name[256];
}Token;

extern int ind;

int ArithOp(char c);
int LogicalOp(char c);
int RelOp(char c);
int isStringLiteral(char line[],int i,int *start_ind);
void createToken(Token token[256],int row_no,int col_no,char *tok,char *str);
void getSpecialSymbol(char line[],int row_no,Token token[256]);
void getArithOp(char line[],int row_no,Token token[256]);

void getLogicalOp(char line[],int row_no,Token token[256]);
void getRelOp(char line[],int row_no,Token token[256]);
void getStringLiteral(char line[],int row_no,Token token[256]);
int isKeyword(char *str);
int isIdentifierChar(char c);
void getIdentifiers(char line[], int row_no, Token token[256]);
void getKeywords(char line[], int row_no, Token token[256]);
void sortTokens(Token *token);
void getNextToken(Token token[],FILE *fa);