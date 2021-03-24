#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

// 0 = stdin
// 1 = stdout
int count;

int main(){
    char f;

    while(read(0, &f, 1)) {
 
    if (f == '\n'){
        count++;
    }
    }
    if (f != '\n'){
        count++;
    }
    printf("%d\n", count);
    return 0;
}