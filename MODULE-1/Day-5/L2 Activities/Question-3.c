/*3. Implement structures to read, write and compute average- marks and the students scoring above
   and below the average marks for a class of N students.*/


#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

struct Student {
    char name[MAX_NAME_LENGTH];
    float marks;
};

void readStudentDetails(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
    }
}

void writeStudentDetails(const struct Student *students, int numStudents) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

float computeAverageMarks(const struct Student *students, int numStudents) {
    float sum = 0.0;
    for (int i = 0; i < numStudents; i++) {
        sum += students[i].marks;
    }
    return sum / numStudents;
}

void findStudentsAboveAndBelowAverage(const struct Student *students, int numStudents, float averageMarks) {
    printf("\nStudents Scoring Above Average Marks:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks > averageMarks) {
            printf("%s\n", students[i].name);
        }
    }

    printf("\nStudents Scoring Below Average Marks:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks < averageMarks) {
            printf("%s\n", students[i].name);
        }
    }
}

int main() {
    int numStudents;
    struct Student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Maximum number of students exceeded. Please try again.\n");
        return 1;
    }

    readStudentDetails(students, numStudents);

    writeStudentDetails(students, numStudents);

    float averageMarks = computeAverageMarks(students, numStudents);
    printf("\nAverage Marks: %.2f\n", averageMarks);

    findStudentsAboveAndBelowAverage(students, numStudents, averageMarks);

    return 0;
}