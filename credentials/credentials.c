
#include <stdio.h>
#include <string.h>
#include <time.h>
#import <stdlib.h>
#import "../mainsplit.c"
#include "LogTrackRecords.c"

#define FILENAME "users.txt"


void storeUser(struct User user) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s %s %s\n", user.username, user.password, user.role);
    fclose(file);
}

void registerCodeRefactor(char *role, struct User *user) {
    printf("\nEnter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
    strcpy(user->role, role);
    storeUser(*user);
    printf("Registration successful!\n");

}


int checkLogin(struct User *user) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    struct User temp;
    while (fscanf(file, "%s %s %s", temp.username, temp.password, temp.role) != EOF) {
        if (strcmp(temp.username, user->username) == 0 && strcmp(temp.password, user->password) == 0) {
            strcpy(user->role, temp.role);
            strcpy(user->username, temp.username);// Set the role of the logged-in user
            fclose(file);
            return 1; // Login successful
        }
    }
    fclose(file);
    return 0; // Login failed
}

void loginUser(struct User *user) {
    if (checkLogin(user)) {
        printf("Login successful!\n");
        if (strcmp(user->role, "Teacher") == 0) {
            printf("\nWelcome to the Teacher's Portal.\n");
            printf("Welcome %s !\n", user->username);
            logTrackTrue(user->username);
            TeachersThing(user);
            // Additional teacher-specific logic
        } else if (strcmp(user->role, "Student") == 0) {
            printf("\nWelcome to the Student's Portal.\n");
            printf("Welcome %s !\n", user->username);
            logTrackTrue(user->username);
            StudentsThing();
            // Additional student-specific logic
        } else if (strcmp(user->role, "Staff Member") == 0) {
            printf("\nWelcome to the Staff Member's Portal.\n");
            printf("Welcome %s !\n", user->username);
            logTrackTrue(user->username);
            StaffThing();
            // Additional staff member-specific logic
        }
    } else {
        logTrackFalse(user->username);
        printf("\nInvalid username or password.\n");
    }
}

void registerUser(struct User *user) {
    int choice;
    printf("\nRegister as,\n");
    printf("> 1. Teacher \n");
    printf("> 2. Student \n");
    printf("> 3. Staff Member \n");
    printf("> Enter the number & hit ENTER: ");

    if (scanf("%d", &choice) == 1) {
        registerCodeRefactor("Teacher", user);
    } else if (scanf("%d", &choice) == 2) {
        registerCodeRefactor("Student", user);
    } else if (scanf("%d", &choice) == 3) {
        registerCodeRefactor("StaffMember", user);
    } else if (scanf("%d", &choice) > 3) {
        printf("Invalid choice. Defaulting to Student.\n");
        registerCodeRefactor("Student", user);
    } else {
        printf("Invalid option. Please try again.\n");
        exit(EXIT_FAILURE);
    }

}


void Credentials() {
    int number;
    struct User user;

    printf("> 1. Login \n");
    printf("> 2. Register \n\n");
    printf("> Enter the number & hit ENTER: ");
    scanf("%d", &number);

    switch (number) {
        case 1:
            printf("\nLogin\n");
            printf("Enter username: ");
            scanf("%s", user.username);
            printf("Enter password: ");
            scanf("%s", user.password);
            loginUser(&user);
            break;
        case 2:
            registerUser(&user);
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }
}
