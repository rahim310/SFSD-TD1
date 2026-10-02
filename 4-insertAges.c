#include <stdio.h>

typedef struct person {
    char name[20];
    int age;
} person;

int main() {
    person people[3];
    printf("Enter the names and ages of 3 people :\n");
    for(int i=0; i<3; i++) {
        printf("== person %d ==\n", i+1);
        printf("name : ");
        scanf("%19s", people[i].name);
        printf("age : ");
        if (scanf("%d", &people[i].age) != 1) { printf("invalid age\n"); return 1; }
    }
    FILE *f = fopen("files/data.txt", "w");
    if(f == NULL) {
        perror("Could not open file");
        return 1;
    }
    for(int i=0; i<3; i++) fprintf(f, "%s: %d\n", people[i].name, people[i].age);
    fclose(f);
    int c;
    f = fopen("files/data.txt", "r");
    if(f == NULL) {
        perror("Could not open file");
        return 1;
    }
    printf("=== content of the file ===\n");
    while((c = fgetc(f)) != EOF) printf("%c", c);
    fclose(f);
    return 0;
}