#include <stdio.h>

int main() {
    char fileName[50];
    printf("enter file path : ");
    scanf("%49s", fileName);
    FILE *f = fopen(fileName, "r");
    if(f == NULL) {
        perror("Could not open file");
        return 1;
    }
    int c, prev = ' ';
    int chars=0, words=0, lines=0; 
    while((c = fgetc(f)) != EOF) {
        chars++;
        if(c == '\n') lines++;
        if(((c != ' ' && c != '\n' && c != '\t') && (prev == ' ' || prev == '\n' || prev == '\t'))) words++;
        prev = c;
    }
    if (chars > 0 && prev != '\n') lines++;
    fclose(f);
    printf("Characters: %d\n", chars);
    printf("Words     : %d\n", words);
    printf("Lines     : %d\n", lines);
    return 0;
}