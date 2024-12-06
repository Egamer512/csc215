#include <stdio.h>

int main(){
    char curr, prev;
    while ((curr=getchar()) != EOF ){
        if (curr == ' ' && prev == ' '){
            continue;
        }else{
            putchar(curr);
        }
        prev = curr;
    }
    return 1;
} 