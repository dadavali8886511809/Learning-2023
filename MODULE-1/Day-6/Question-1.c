/*   **********Level-1:***********

1. Assume User will be providing input in the form of a string as show below. 
Write a function to parse the string and initialize an array of structures. 

Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };

Note: User must be able define the no. of inputs/size of the array during runtime. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parse_string(const char* input, struct Student* students, int num_students) {
    char* token;

    char* input_copy = strdup(input);

    token = strtok(input_copy, " ");

    for (int i = 0; i < num_students; i++) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strcpy(students[i].name, token);

        token = strtok(NULL, " ");
        students[i].marks = atof(token);


        token = strtok(NULL, " ");
    }

    free(input_copy);
}

int main() {
    const char* input = "1001 Aron 100.00";
    int num_students = 1;

    struct Student* students = (struct Student*)malloc(num_students * sizeof(struct Student));

    parse_string(input, students, num_students);

    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    free(students);

    return 0;
}