#include <stdio.h>
#include <string.h>
#include <time.h>

char *delwink_get_date_stamp()
{
    const char *zero = "0";
    time_t time = time(NULL);
    struct tm *now = localtime(&time);
    char *s = malloc(15);
    int i;

    char *date[] = {
        malloc(5),
        malloc(3),
        malloc(3),
        malloc(3),
        malloc(3),
        malloc(3)
    };

    sprintf(date[0], "%d", now->tm_year+1900); 

    if (now->tm_mon+1 < 10) {
        strcat(date[1], zero);
        char *temp = malloc(2);
        sprintf(temp, "%d", now->tm_mon+1);
        strcat(date[1], temp);
        free(temp);
    } else {
        sprintf(date[1], "%d", now->tm_mon+1);
    }

    if (now->tm_mday < 10) {
        strcat(date[2], zero);
        char *temp = malloc(2);
        sprintf(temp, "%d", now->tm_mday);
        strcat(date[2], temp);
        free(temp);
    } else {
        sprintf(date[2], "%d", now->tm_mday);
    }

    if (now->tm_hour < 10) {
        strcat(date[3], zero);
        char *temp = malloc(2);
        sprintf(temp, "%d", now->tm_hour);
        strcat(date[3], temp);
        free(temp);
    } else {
        sprintf(date[3], "%d", now->tm_hour);
    }

    if (now->tm_min < 10) {
        strcat(date[4], zero);
        char *temp = malloc(2);
        sprintf(temp, "%d", now->tm_min);
        strcat(date[4], temp);
        free(temp);
    } else {
        sprintf(date[4], "%d", now->tm_min);
    }

    if (now->tm_sec < 10) {
        strcat(date[5], zero);
        char *temp = malloc(2);
        sprintf(temp, "%d", now->tm_sec);
        strcat(date[5], temp);
        free(temp);
    } else {
        sprintf(date[5], "%d", now->tm_sec);
    }

    for (i = 0; i < 6; ++i) {
        strcat(s, date[i]);
        free(date[i]);
    }

    return s;
}
