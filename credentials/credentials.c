//#include <stdio.h>
//#include <string.h>
//
//#define FILENAME "users.txt"
//
//struct User {
//    char username[50];
//    char password[50];
//};
//
//void storeUser(struct User user) {
//    FILE *file = fopen(FILENAME, "a");
//    if (file == NULL) {
//        printf("Error opening file!\n");
//        return;
//    }
//    fprintf(file, "%s %s\n", user.username, user.password);
//    fclose(file);
//}
//
//int checkLogin(struct User user) {
//    FILE *file = fopen(FILENAME, "r");
//    if (file == NULL) {
//        printf("Error opening file!\n");
//        return 0;
//    }
//
//    struct User temp;
//    while (fscanf(file, "%s %s", temp.username, temp.password) != EOF) {
//        if (strcmp(temp.username, user.username) == 0 && strcmp(temp.password, user.password) == 0) {
//            fclose(file);
//            return 1; // Login successful
//        }
//    }
//
//    fclose(file);
//    return 0; // Login failed
//}
//
//void Credentials() {
//    int number;
//    int choice;
//    struct User user;
//
//
//    printf("> 1. Login \n");
//    printf("> 2. Register \n\n");
//    printf("> Enter the number & hit ENTER: ");
//    scanf("%d", &number);
//
//    switch (number) {
//        case (1):
//            printf("\nLogin\n");
//            printf("Enter username: ");
//            scanf("%s", user.username);
//            printf("Enter password: ");
//            scanf("%s", user.password);
//
//            if (checkLogin(user)) {
//                printf("Login successful!\n");
//            } else {
//                printf("Invalid username or password.\n");
//            }
//            break;
//        case (2):
//            printf("\nRegister as,\n");
//            printf("> 1. Teacher \n");
//            printf("> 2. Student \n");
//            printf("> 3. Staff Member \n");
//            printf("> Enter the number & hit ENTER: ");
//            scanf("%d", &number);
//            switch (number) {
//                case 1:
//                    printf("\nEnter username: ");
//                    scanf("%s", user.username);
//                    printf("Enter password: ");
//                    scanf("%s", user.password);
//                    storeUser(user);
//                    printf("Registration successful!\n");
//                    break;
//                case 2:
//                    printf("\nEnter username: ");
//                    scanf("%s", user.username);
//                    printf("Enter password: ");
//                    scanf("%s", user.password);
//                    storeUser(user);
//                    printf("Registration successful!\n");
//                    break;
//                case 3:
//                    printf("\nEnter username: ");
//                    scanf("%s", user.username);
//                    printf("Enter password: ");
//                    scanf("%s", user.password);
//                    storeUser(user);
//                    printf("Registration successful!\n");
//            break;
//            }
//
//            break;
//
//    }
//
//}
#include <stdio.h>
#include <string.h>
#include <time.h>

#define FILENAME "users.txt"

struct User {
    char username[50];
    char password[50];
    char role[20];
};

void logTrack(char* user){
    FILE *fptrForLog = fopen("./loginRecords/logtrack.html","a");

    time_t current_time;
    // Get the current time
    time(&current_time);

    struct tm *local_time = localtime(&current_time);

    char time_string[100];

    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

    fprintf(fptrForLog,"\n<h4>%s logged at  %s</h4>\n",user, time_string);
    fclose(fptrForLog);

}

void storeUser(struct User user) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s %s %s\n", user.username, user.password, user.role);
    fclose(file);
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
            strcpy(user->username,temp.username);// Set the role of the logged-in user
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
            printf("Welcome to the Teacher's Portal.\n");
            printf("Welcome %s !\n",user->username);
            logTrack(user->username);

            // Additional teacher-specific logic
        } else if (strcmp(user->role, "Student") == 0) {
            printf("Welcome to the Student's Portal.\n");
            printf("Welcome %s !\n",user->username);
            logTrack(user->username);
            // Additional student-specific logic
        } else if (strcmp(user->role, "Staff Member") == 0) {
            printf("Welcome to the Staff Member's Portal.\n");
            printf("Welcome %s !\n",user->username);
            logTrack(user->username);
            // Additional staff member-specific logic
        }
    } else {
        printf("Invalid username or password.\n");
    }
}

void registerUser(struct User *user) {
    int choice;
    printf("\nRegister as,\n");
    printf("> 1. Teacher \n");
    printf("> 2. Student \n");
    printf("> 3. Staff Member \n");
    printf("> Enter the number & hit ENTER: ");
    scanf("%d", &choice);

    printf("\nEnter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);

    switch (choice) {
        case 1:
            strcpy(user->role, "Teacher");
            break;
        case 2:
            strcpy(user->role, "Student");
            break;
        case 3:
            strcpy(user->role, "Staff Member");
            break;
        default:
            printf("Invalid choice. Defaulting to Student.\n");
            strcpy(user->role, "Student");
    }

    storeUser(*user);
    printf("Registration successful!\n");
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
