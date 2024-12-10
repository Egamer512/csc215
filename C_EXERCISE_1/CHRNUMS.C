#include <stdio.h>
#define MAXLINE 80

main(argc, argv)
    int argc;
    char* argv[];
{
    FILE *infp;
    int count, len;
    char words[MAXLINE];

    if (argc != 2){
        printf("Usage: <infile>\n");
        exit();
    }
    if((infp = fopen(argv[1], "r")) == NULL){
        printf("Can't open %s\n", argv[1]);
        exit();
    }

}
