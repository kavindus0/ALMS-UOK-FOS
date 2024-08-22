#import <stdio.h>
#import "./communication/Communication.c"

struct User {
    char username[50];
    char password[50];
    char role[20];
};

void TeachersThing(char *user);
void StudentsThing();
void StaffThing();
void HR();
void ExtraActivities();
void TimeTable();
void EDUcom(char *user);


void TeachersThing(char *user) {


    int input;
    printf("\n1. EDUconnect Communication Portal\n2. HR\n3. Extra Activities\n4. Time Table\n\nEnter a number: ");
    scanf("%d", &input);
    switch (input) {
        case 1:
            EDUcom(user);
            printf("%s\n", user);
            break;
        case 2:
            HR();
            break;
        case 3:
            ExtraActivities();
            break;
        case 4:
            TimeTable();
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}

void StudentsThing() {
    printf("Student Thing\n");
}

void StaffThing() {
    printf("Staff Thing\n");
}

void HR() {
    printf("HR\n");
}

void ExtraActivities() {
    printf("Extra Activities\n");
}

void TimeTable() {
    printf("Time Table\n");
}

void EDUcom(char *user) {
    printf("\n---- EDUconnect Communication Portal -----\n");
    printf("\n---- Logged As %s -----\n",user);
    printf("1. School Announcement\n");
    printf("2. Open Portal\n");
    printf("Enter a number and Hit ENTER: ");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            printf("\nSchool Announcement Logged\n");
            printf("\nWrite And HIT ENTRE to Send a Notification to Announcement\n");
            char announcement[100];
            scanf("%s", announcement);
            FILE *fptrForAnnounce = fopen("./communication/SchoolAnnouncement/index.html","a");
    if (fptrForAnnounce == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fptrForAnnounce, "%s", announcement);

            printf("%s Successfully Printed\n", user);
            fclose(fptrForAnnounce);
            break;
        case 2:
            printf("\nOpen Portal Logged\n");
            break;
        default:
            printf("\nInvalid input\n");
            break;
    }
}
