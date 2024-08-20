//
// Created by kavindu on 2024-08-20.
//

#import "../mainsplit.c"
#import <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "LogTrackRecords.h"

void logTrackTrue(char* user){
    FILE *fptrForLog = fopen("./loginRecords/logtrack.html","a");

    time_t current_time;
    // Get the current time
    time(&current_time);

    struct tm *local_time = localtime(&current_time);

    char time_string[100];

    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

    fprintf(fptrForLog,"\n<h4>user <i>%s</i> Successfully logged at  %s</h4>\n<br>",user, time_string);
    fclose(fptrForLog);

}

void logTrackFalse(char* user){
    FILE *fptrForLog = fopen("./loginRecords/logtrack.html","a");

    time_t current_time;
    // Get the current time
    time(&current_time);

    struct tm *local_time = localtime(&current_time);

    char time_string[100];

    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

    fprintf(fptrForLog,"\n<h4 class=\"logFail\">Unrecognize Loggin Attempt Prohibited for username:<i> %s </i> at  %s</h4>\n<br>",user, time_string);
    fclose(fptrForLog);

}