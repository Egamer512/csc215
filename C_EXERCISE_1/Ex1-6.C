#include <stdio.h>
#define EOF -1

int main(){
    int c, nl, blank, tab;
    nl = 0;
    blank = 0;
    tab = 0;
    while ( (c = getchar()) != EOF){
        if (c == '\n'){
            ++nl;
        }
        if (c == '\t'){
            ++tab;
        }
        if (c == ' '){
            ++blank;
        }
        printf("New Lines: %d\n", nl);
        printf("Tabs: %d\n", tab);
        printf("Blanks: %d\n", blank);
        
        return 1;
    }
}