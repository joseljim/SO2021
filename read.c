#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    int records = atoi(argv[2]);
    FILE *forigen;
    forigen = fopen(filename,"rb");

    for (int i = 0; i < records; i++) {
        STUDENT newstudent;
        fread(&newstudent,sizeof(newstudent),1,forigen);
        printf("%s %s %d %d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);

    }
    fclose(forigen);

    return 0;
}