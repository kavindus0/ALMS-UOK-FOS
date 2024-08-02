#include <stdio.h>
#include <stdlib.h>


void Credentials() {
    int number;

    printf("> 1. Login \n");
    printf("> 2. Register \n\n");
    printf("> Enter the number & hit ENTER: ");
    scanf("%d", &number);

    switch (number) {
        case (1):
            printf("Login");
            break;
        case (2):
            printf("Register as,\n");
            printf("> 1. Teacher \n");
            printf("> 2. Student \n");
            printf("> 3. Staff Member \n");
            printf("> Enter the number & hit ENTER: ");
            scanf("%d", &number);
            switch (number) {
                case 1:
                    printf("Enter Username:");
                case 2:
                    printf("");
                case 3:
                    printf("");


            }




            break;

    }

}
