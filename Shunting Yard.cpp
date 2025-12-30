
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1024

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void push(CharStack *s, char x){ s->data[++s->top]=x; }
char pop(CharStack *s){ return s->data[s->top--]; }
char peek(CharStack *s){ return s->data[s->top]; }
int empty(CharStack *s){ return s->top==-1; }

int prec(char op){
    if(op=='^') return 3;
    if(op=='*'||op=='/') return 2;
    if(op=='+'||op=='-') return 1;
    return 0;
}
int rightAssoc(char op){ return op=='^'; }

int main(){
    char expr[MAX];
    printf("Enter infix (no spaces recommended): ");
    scanf("%s", expr);

    CharStack ops; ops.top=-1;
    char out[MAX]; int outLen=0;

    for(int i=0; expr[i]; i++){
        char ch = expr[i];

        if(isdigit((unsigned char)ch)){
            // multi-digit number
            while(expr[i] && isdigit((unsigned char)expr[i])) {
                out[outLen++] = expr[i++];
            }
            out[outLen++]=' ';
            i--;
        }
        else if(ch=='('){
            push(&ops,ch);
        }
        else if(ch==')'){
            while(!empty(&ops) && peek(&ops)!='('){
                out[outLen++]=pop(&ops);
                out[outLen++]=' ';
            }
            if(!empty(&ops) && peek(&ops)=='(') pop(&ops);
        }
        else { // operator
            while(!empty(&ops) && peek(&ops)!='('){
                char topOp = peek(&ops);
                if(prec(topOp) > prec(ch) || (prec(topOp)==prec(ch) && !rightAssoc(ch))){
                    out[outLen++]=pop(&ops);
                    out[outLen++]=' ';
                } else break;
            }
            push(&ops,ch);
        }
    }
    while(!empty(&ops)){
        out[outLen++]=pop(&ops);
        out[outLen++]=' ';
    }
    out[outLen]=0;

    printf("Postfix: %s\n", out);
    return 0;
}

