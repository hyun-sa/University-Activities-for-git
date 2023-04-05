#include <stdio.h>
char lookahead;
int x = 0;
int y = 0;


void match(char token);
void nexttoken();
void seq();
void instr();
void prt_pos();


int main() {
    nexttoken();
    if (lookahead == 'b') {
        seq();
    }
    else {
        printf("error\n");
    }

    return 0;
}


void match(char token) {
    if (lookahead == token)
        nexttoken();
    else {
        printf("error\n");
        return;
    }
}


void nexttoken() {
    char c;
    while (1) {
        c = getchar();
        if (c == EOF) {
            lookahead = '$';
            return;
        }
        if (c == ' ' || c == '\t' || c == '\n' || c == '\0') continue;
        lookahead = c;
        return;
    }
}


void seq()
{
    match('b');
    prt_pos();
    if (lookahead == 'e' || lookahead == 'n' || lookahead == 'w' || lookahead == 's' || lookahead == '$') {
        instr();
    }
    else {
        printf("error");
    }
}


void instr()
{
    if (lookahead == 'e') {
        match('e');
        x += 1;
        prt_pos();
        instr();
    }
    else if (lookahead == 'n') {
        match('n');
        y += 1;
        prt_pos();
        instr();
    }
    else if (lookahead == 'w') {
        match('w');
        x -= 1;
        prt_pos();
        instr();
    }
    else if (lookahead == 's') {
        match('s');
        y -= 1;
        prt_pos();
        instr();
    }
    else if (lookahead == '$') {
        printf("\n");
    }
    else {
        printf("error");
    }
}


void prt_pos()
{
    printf("(%d, %d) ", x, y);
}