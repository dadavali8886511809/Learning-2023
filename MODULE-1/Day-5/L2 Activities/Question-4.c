/*4. Write a program to pass a pointer to a structure as a parameter to a function and return back a pointer to structure 
   to the calling function after modifying the members of structure.*/



#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

void modifyAge(struct Person* person) {
    person->age += 1;
}

struct Person* getModifiedPerson(struct Person* person) {
    modifyAge(person);
    return person;
}

int main() {

    struct Person person;

    printf("Enter the person's name: ");
    scanf("%s", person.name);

    printf("Enter the person's age: ");
    scanf("%d", &(person.age));

    struct Person* modifiedPerson = getModifiedPerson(&person);

    printf("\nModified Person:\n");
    printf("Name: %s\n", modifiedPerson->name);
    printf("Age: %d\n", modifiedPerson->age);

    return 0;
}