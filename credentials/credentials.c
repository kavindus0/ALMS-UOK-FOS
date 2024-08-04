#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILENAME "users.txt"

struct User {
    char username[50];
    char password[50];
};

void storeUser(struct User user) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s %s\n", user.username, user.password);
    fclose(file);
}

int checkLogin(struct User user) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    struct User temp;
    while (fscanf(file, "%s %s", temp.username, temp.password) != EOF) {
        if (strcmp(temp.username, user.username) == 0 && strcmp(temp.password, user.password) == 0) {
            fclose(file);
            return 1; // Login successful
        }
    }

    fclose(file);
    return 0; // Login failed
}

void Credentials() {
    int number;
    int choice;
    struct User user;


    printf("> 1. Login \n");
    printf("> 2. Register \n\n");
    printf("> Enter the number & hit ENTER: ");
    scanf("%d", &number);

    switch (number) {
        case (1):
            printf("\nLogin\n");
            printf("Enter username: ");
            scanf("%s", user.username);
            printf("Enter password: ");
            scanf("%s", user.password);

            if (checkLogin(user)) {
                printf("Login successful!\n");
            } else {
                printf("Invalid username or password.\n");
            }
            break;
        case (2):
            printf("\nRegister as,\n");
            printf("> 1. Teacher \n");
            printf("> 2. Student \n");
            printf("> 3. Staff Member \n");
            printf("> Enter the number & hit ENTER: ");
            scanf("%d", &number);
            switch (number) {
                case 1:
                    printf("\nEnter username: ");
                    scanf("%s", user.username);
                    printf("Enter password: ");
                    scanf("%s", user.password);
                    storeUser(user);
                    printf("Registration successful!\n");
                    break;
                case 2:
                    printf("Enter username: ");
                    scanf("%s", user.username);
                    printf("Enter password: ");
                    scanf("%s", user.password);
                    storeUser(user);
                    printf("Registration successful!\n");
                    break;
                case 3:
                    printf("Enter username: ");
                    scanf("%s", user.username);
                    printf("Enter password: ");
                    scanf("%s", user.password);
                    storeUser(user);
                    printf("Registration successful!\n");
            break;
            }

            break;

    }

}
