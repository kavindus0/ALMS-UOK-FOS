#import <stdio.h>
#import "./communication/Communication.c"
#include <time.h>
#include <stdio.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
    char role[20];
};

void TeachersThing(char *user);

void StudentsThing();

void StaffThing(char *user);

void HR();

void ExtraActivities();

void TimeTable();

void EDUcomTchr(char *user);
void EDUcomStaff(char *user);


void TeachersThing(char *user) {
    int input;
    printf("\n1. EDUconnect Communication Portal\n2. HR\n3. Extra Activities\n4. Time Table\n\nEnter a number: ");
    scanf("%d", &input);
    switch (input) {
        case 1:
            EDUcomTchr(user);
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

void StaffThing(char *user) {
    printf("Staff Thing\n");
    int input;
    printf("\n1. EDUconnect Communication Portal\n2. HR\n3. Extra Activities\n4. Time Table\n\nEnter a number: ");
    scanf("%d", &input);
    switch (input) {
        case 1:
            EDUcomStaff(user);
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

void HR() {
    printf("HR\n");
}

void ExtraActivities() {
    printf("Extra Activities\n");
}

void TimeTable() {
    printf("Time Table\n");
}




void EDUcomTchr(char *user) {
    printf("\n---- EDUconnect Communication Portal -----\n");
    printf("\n---- Logged As %s -----\n", user);
    printf("1. School Announcement\n");
    printf("2. Open Portal\n");
    printf("Enter a number and Hit ENTER: ");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            printf("\nSchool Announcement Logged\n");
            printf("\nWrite And HIT ENTRE to Send a Notification to Announcement\n");
            char announcement[10000];
            getchar(); // To consume the newline character left by previous scanf
            fgets(announcement, sizeof(announcement), stdin);

            FILE *fptrForAnnounce = fopen("./communication/SchoolAnnouncement/index.html", "a");
            if (fptrForAnnounce == NULL) {
                printf("Error opening file!\n");
                return;
            }
            time_t t;
            struct tm *tm_info;

            time(&t);
            tm_info = localtime(&t);

            char buffer[26];
            strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            // printf("Current Date and Time: %s\n", buffer);
            fprintf(fptrForAnnounce, "<div class=\"message-bubble-tchr\">\n");
            fprintf(fptrForAnnounce, "    <div class=\"sender-name\">%s</div>\n", user);
            fprintf(fptrForAnnounce, "    <div class=\"message-body\">%s</div>\n", announcement);
            fprintf(fptrForAnnounce, "    <div class=\"message-time\">%s</div>\n", buffer);
            fprintf(fptrForAnnounce, "</div>\n");
            printf("Message Successfully Sent at : %s\n", buffer);
            fclose(fptrForAnnounce);
            break;
        case 2:
            printf("\nOpen Portal Logged\n");
            printf("\nSchool Open Portal Logged\n");
            printf("\nWrite And HIT ENTRE to Send a Notification to Announcement\n");
            char announcement4Open[10000];
            getchar();
            fgets(announcement4Open, sizeof(announcement), stdin);
            FILE *fptrForOpen = fopen("./communication/OpenPortal/index.html", "a");

            if (fptrForOpen == NULL) {
                printf("Error opening file!\n");
                return;
            }
            //time_t t;
            //struct tm *tm_info;
            time(&t);
            tm_info = localtime(&t);

            //char buffer[26];

            strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            // printf("Current Date and Time: %s\n", buffer);
            fprintf(fptrForOpen, "<div class=\"message-bubble\">\n");
            fprintf(fptrForOpen, "    <div class=\"sender-name\">%s</div>\n", user);
            fprintf(fptrForOpen, "    <div class=\"message-body\">%s</div>\n", announcement4Open);
            fprintf(fptrForOpen, "    <div class=\"message-time\">%s</div>\n", buffer);
            fprintf(fptrForOpen, "</div>\n");
            printf("Message Successfully Sent at : %s\n", buffer);
            fclose(fptrForOpen);
            break;
        default:
            printf("\nInvalid input\n");
            break;
    }
}

void EDUcomStaff(char *user) {
    printf("\n---- EDUconnect Communication Portal -----\n");
    printf("\n---- Logged As %s -----\n", user);
    printf("1. School Announcement\n");
    printf("2. Open Portal\n");
    printf("Enter a number and Hit ENTER: ");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            printf("\nSchool Announcement Logged\n");
            printf("\nWrite And HIT ENTRE to Send a Notification to Announcement\n");
            char announcement[10000];
            getchar(); // To consume the newline character left by previous scanf
            fgets(announcement, sizeof(announcement), stdin);
            FILE *fptrForAnnounce = fopen("./communication/SchoolAnnouncement/index.html", "a");
            if (fptrForAnnounce == NULL) {
                printf("Error opening file!\n");
                return;
            }
            time_t t;
            struct tm *tm_info;
            time(&t);
            tm_info = localtime(&t);
            char buffer[26];
            strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            // printf("Current Date and Time: %s\n", buffer);
            fprintf(fptrForAnnounce, "<div class=\"message-bubble-stf\">\n");
            fprintf(fptrForAnnounce, "    <div class=\"sender-name\">%s</div>\n", user);
            fprintf(fptrForAnnounce, "    <div class=\"message-body\">%s</div>\n", announcement);
            fprintf(fptrForAnnounce, "    <div class=\"message-time\">%s</div>\n", buffer);
            fprintf(fptrForAnnounce, "</div>\n");
            printf("Message Successfully Sent at : %s\n", buffer);
            fclose(fptrForAnnounce);
            break;
        case 2:
            printf("\nOpen Portal Logged\n");
             printf("\nSchool Open Portal Logged\n");
            printf("\nWrite And HIT ENTRE to Send a Notification to Announcement\n");
            char announcement4Open[10000];
            getchar(); // To consume the newline character left by previous scanf
            fgets(announcement, sizeof(announcement), stdin);
            FILE *fptrForOpen = fopen("./communication/OpenPortal/index.html", "a");
            if (fptrForAnnounce == NULL) {
                printf("Error opening file!\n");
                return;
            }
            //time_t t;
            //struct tm *tm_info;
            time(&t);
            tm_info = localtime(&t);

            //char buffer[26];

            strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            // printf("Current Date and Time: %s\n", buffer);
            fprintf(fptrForAnnounce, "<div class=\"message-bubble\">\n");
            fprintf(fptrForAnnounce, "    <div class=\"sender-name\">%s</div>\n", user);
            fprintf(fptrForAnnounce, "    <div class=\"message-body\">%s</div>\n", announcement);
            fprintf(fptrForAnnounce, "    <div class=\"message-time\">%s</div>\n", buffer);
            fprintf(fptrForAnnounce, "</div>\n");
            printf("Message Successfully Sent at : %s\n", buffer);
            fclose(fptrForAnnounce);
            break;
        default:
            printf("\nInvalid input\n");
            break;
    }
}
void EDUcomStud(char *user) {
    printf("\n---- EDUconnect Communication Portal -----\n");
    printf("\n---- Logged As %s -----\n", user);
    printf("1. Open Portal\n");
    printf("Enter a number and Hit ENTER: ");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            printf("\nSchool Open Portal Logged\n");
            printf("\nWrite And HIT ENTRE to Send a Notification to Announcement\n");
            char announcement[10000];
            getchar(); // To consume the newline character left by previous scanf
            fgets(announcement, sizeof(announcement), stdin);
            FILE *fptrForAnnounce = fopen("./communication/OpenPortal/index.html", "a");
            if (fptrForAnnounce == NULL) {
                printf("Error opening file!\n");
                return;
            }
            time_t t;
            struct tm *tm_info;
            time(&t);
            tm_info = localtime(&t);
            char buffer[26];
            strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            // printf("Current Date and Time: %s\n", buffer);
            fprintf(fptrForAnnounce, "<div class=\"message-bubble\">\n");
            fprintf(fptrForAnnounce, "    <div class=\"sender-name\">%s</div>\n", user);
            fprintf(fptrForAnnounce, "    <div class=\"message-body\">%s</div>\n", announcement);
            fprintf(fptrForAnnounce, "    <div class=\"message-time\">%s</div>\n", buffer);
            fprintf(fptrForAnnounce, "</div>\n");
            printf("Message Successfully Sent at : %s\n", buffer);
            fclose(fptrForAnnounce);
            break;
        default:
            printf("\nInvalid input\n");
            break;
    }
}
