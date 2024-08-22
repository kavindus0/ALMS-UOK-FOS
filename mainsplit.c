//
// Created by kavindu on 2024-08-20.
//
#import <stdio.h>
#import "./communication/Communication.c"


void TeachersThing(){

    void EDUconnectCommunicationPortal();
    void HR();
    void ExtraActivities();
    void TimeTable();

    int input;
    printf("\n1. EDUconnect Communication Portal\n2. HR\n3. Extra Activities\n4. Time Table\n\nEnter a number:");
    scanf("%d", &input);
        switch (input) {
        case 1:
            EDUconnectCommunicationPortal();
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

void StudentsThing(){
    printf("Student Thing");
}

void StaffThing(){
    printf("Staff Thing");
}



void EDUconnectCommunicationPortal() {
    printf("\n---- EDUconnect Communication Portal -----\n");
    printf("1.School Announcement\n");
    printf("2.Open Portal\n");
    printf("Enter a number and Hit ENTRE: ");
    int input;
    scanf("%d", &input);
    switch (input) {
        case 1:
            printf("\nSchool Announcement Logged\n");
            break;
        case 2:
            printf("\nOpen Portal Logged\n");
            break;
        default:
            printf("\nInvalid input\n");
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