#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

struct student {
    int id;
    char name[MAX_NAME_LENGTH];
    float GPA;
};

struct student students[MAX_STUDENTS];
int numstudents = 0;

void addstudent() {
    if (numstudents < MAX_STUDENTS) {
        struct student newstudent;
        printf("Enter student ID:");
        scanf("%d", &newstudent.id);
        printf("Enter student name:");
        scanf("%s", newstudent.name);
        printf("Enter student GPA:");
        scanf("%f", &newstudent.GPA);

        students[numstudents] = newstudent;
        numstudents++;
        printf("Student added successfully\n");
    } else {
        printf("Maximum number of students reached\n");
    }
}

void displaystudents() {
    printf("ID\tName\tGPA\n");
    for (int i = 0; i < numstudents; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].GPA);
    }
}

void searchstudent(int id) {
    for (int i = 0; i < numstudents; i++) {
        if (students[i].id == id) {
            printf("Student Found:\n");
            printf("ID:%d\nName:%s\nGPA: %.2f\n", students[i].id, students[i].name, students[i].GPA);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

int main() {
    int choice, id;

    do {
        printf("\nStudent Management System\n");
        printf("1.Add Students\n");
        printf("2.Display Students\n");
        printf("3.Search students\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addstudent();
                break;
            case 2:
                displaystudents();
                break;
            case 3:
                printf("Enter student id to search:");
                scanf("%d", &id);
                searchstudent(id);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


