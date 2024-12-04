#include <stdio.h>

main(argc, argv)
int argc;
char *argv[];
{
    int i;
    int sum;
    sum = 0;

    for(i = 1; i < argc; i++){
        int num;
        num = atoi(argv[i]);
        if(num == 0){
            printf("OOPS! %s is not a number", argv[i]);
            return 1;
        }
        sum += num;
    }
    printf("%d", total);
    return 0;
}