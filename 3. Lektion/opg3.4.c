#include<stdio.h>

#define MIN (sec / 60)
#define HOUR (MIN / 60)
#define DAYS (HOUR / 24)
#define WEEKS (DAYS / 7)

int sec = 0;

int main (void) {
    printf("Indtast antal sekunder der skal omregnes til uger, dage, timer, minutter og sekunder: ");
    scanf("%d", &sec);
    printf("%d sekunder svarer til:", sec);

    if (WEEKS > 0)
    {
        char *c = (WEEKS > 1) ? "uger" : "uge";
        printf("\n  - %d %s", WEEKS, c);
    }
    if (DAYS % 7 > 0)
    {
        char *c = ((DAYS % 7) > 1) ? "dage" : "dag";
        printf("\n  - %d %s", DAYS % 7, c);
    }
    if (HOUR % 24 > 0)
    {
        char *c = ((HOUR % 24) > 1) ? "timer" : "time";
        printf("\n  - %d %s", HOUR % 24, c);
    }
    if (MIN % 60 > 0)
    {
        char *c = ((MIN % 60) > 1) ? "minutter" : "minut";
        printf("\n  - %d %s", MIN % 60, c);
    }
    if (sec % 60 > 0)
    {
        char *c = ((sec % 60) > 1) ? "sekunder" : "sekund";
        printf("\n  - %d %s", sec % 60, c);
    }
    printf("\n");

    return 0;
}