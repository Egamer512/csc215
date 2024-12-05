#include <stdio.h>

main(){
    char str[150];
    int i;
    i=0;
    char curr;
    int c;
    while(c=getchar() != EOF){
        curr = getchar();
        if(curr != " "){
            str[i] = " ";
        }
    }
}