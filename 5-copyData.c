#include <stdio.h>

int main() {
    FILE *source = fopen("files/data.txt", "r");
    FILE *dest = fopen("files/copy.txt", "w");
    if (source == NULL || dest == NULL) {
        perror("could not open files");
        if(source) fclose(source);
        if(dest) fclose(dest);
        return 1;
    }
    int c;
    while((c = fgetc(source)) != EOF) fputc(c, dest);
    printf("data copied successfully\n");
    fclose(source);
    fclose(dest);
    return 0;
}