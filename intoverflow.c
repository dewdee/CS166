#include <stdio.h>
#include <string.h>

int copy_something(char* buf, int len);

int main(){

    char* buf = "Hello";

    int x;
    x = copy_something(buf, -65536);

    printf("%d", x);
    return 0;
}

int copy_something(char *buf, int len){
    char kbuf[800];

    if(len > sizeof(kbuf)){         /* [1] */
        return -1;
    }

    return memcpy(kbuf, buf, len);  /* [2] */
}
