#include <stdio.h>

int main() {
    char names[5][20];
    printf("Enter the names of 5 students :\n");
    for(int i=0; i<5; i++) {
        printf("Student %d : ", i+1);
        scanf("%19s", names[i]);
    }
    FILE *f = fopen("files/students.txt", "w");
    if(f == NULL) {
        perror("Could not open file");
        return 1;
    }
    for(int i=0; i<5; i++) fprintf(f, "%s\n", names[i]);
    fclose(f);
    return 0;
}