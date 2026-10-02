#include <stdio.h>

int main() {
    char fileName[50];
    printf("enter file path : ");
    scanf("%49s", fileName);
    FILE *f = fopen(fileName, "r");
    if (f) { fclose(f); printf("the file exists\n"); }
    else printf("the file doesn't exist\n");
    return 0;
}
