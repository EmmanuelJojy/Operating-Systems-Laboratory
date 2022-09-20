#include <stdio.h>
#include <sys/stat.h>

int main(void){

    char *szPath = "hello.c";
    mode_t sMode;

    struct stat SMeta;

    stat(szPath, &SMeta);

    sMode = SMeta.st_mode;

    printf("The mode for %s is %d\n", szPath, sMode);

    for(int i = 15; i >= 0; i--){
        if(sMode & (1 << i)){
            putchar('1');
        } else {
            putchar('0');
        }
        if(i==12){
            putchar(' ');
        }
    }

    putchar('\n');    

    return 0;
}
