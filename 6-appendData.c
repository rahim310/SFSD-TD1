#include <stdio.h>

int main() {
    char buffer[50];
    printf("enter text :\n");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("No text entered.");
        return 1;
    }
    FILE *f = fopen("files/data.txt", "a");
    if (f == NULL) {
        perror("could not open file");
        return 1;
    }
    fputs(buffer, f);
    fclose(f);
    printf("Text appended to data.txt\n");
    return 0;
}