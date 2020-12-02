#include<stdio.h>

int main (void) {
    int sec = 0,    //Initialisere mine variabler
    min = 0,        //
    hour = 0,       //
    days = 0,       //
    weeks = 0;      //

    printf("Indtast antal sekunder der skal omregnes til uger, dage, timer, minutter og sekunder: ");
    scanf("%d", &sec);
    printf("%d sekunder svarer til ", sec);
    
    min = sec / 60;     //Omregner enheden til den nye: sec -> min, min -> hour, etc.
    hour = min / 60;    //
    days = hour / 24;   //
    weeks = days / 7;   //

    sec %= 60;          //Fjerner "overskudet", ved hjælp af modulo
    min %= 60;          //
    hour %= 60;         //
    days %= 24;         //Alternativt kunne disse tal sagtens være nogle konstante int eller symbolske konstanter, hvis der er behov for systematisk ændring i programmet i fremtiden, 
    weeks %= 7;         //men da tidsenheder nok ikke ændre sig foreløbig er der ikke et stort behov for det

    printf("%d uger, %d dage, %d timer, %d minutter og %d sekunder.\n", weeks, days, hour, min, sec);

    return 0;
}