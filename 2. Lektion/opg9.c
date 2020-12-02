/*
Write a program that takes the length and width of a rectangular yard and the length and width of a rectangular house situated in the yard.
Your program should compute the time required to cut the grass at the rate of two square feet a second
*/
#include<stdio.h>

#define CUT_RATE (gArea / 2)
#define CAL_AREA (x * y)

int main (void) {
    double x, y, hArea, gArea, tArea, time;

    printf("Input the area of the ground (yard and house) in 'AxB'-format: ");
    scanf("%lfx%lf", &x, &y);
    tArea = CAL_AREA;

    printf("\nInput the area of the house only in 'AxB'-format: ");
    scanf("%lfx%lf", &x, &y);
    hArea = CAL_AREA;
    gArea = tArea - hArea;
    time = CUT_RATE;
    printf("\nWith %1.3f square feet of grass to cut, it should take you %1.3f seconds to do it\n", gArea, time);
    
    return 0;
}