//
// Created by kavindu on 2024-08-20.
//
#import <stdio.h>
#import "./communication/Communication.c"
#import <string.h>


void TeachersThing(){

void EDUconnectCommunicationPortal();
void HR();
void ExtraActivities();
void TimeTable();

     int input;
    printf("\nEnter a number:\n1. EDUconnect Communication Portal\n2. HR\n3. Extra Activities\n4. Time Table\n");
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
    printf("Teachers Thing");

}

void StaffThing(){
    printf("Teachers Thing");

}



void EDUconnectCommunicationPortal() {
    printf("EDUconnect Communication Portal\n");
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