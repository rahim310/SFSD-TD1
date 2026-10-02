#include <stdio.h>

int main() {
    FILE *f = fopen("files/students.txt", "r");
    if(f == NULL) {
        perror("Could not open file");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), f)) printf("%s", line);
    fclose(f);
    return 0;
}