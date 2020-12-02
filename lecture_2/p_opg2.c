/*
    a.  Write a statement that displays the following line with the value of the type int variable n before the period.
        The value of n is ___________.
    b.  Assuming that side and area are type double variables containing the length of one side in cm and the area of a square in square cm,
        write a statement that will display this information in this form:
        
        The area of a square whose side length is ______ cm is ______ square cm.
*/

#include<stdio.h>


int main (void) {
    double side, square;
    printf("calculate the area of a aquare with an side length of: ");
    scanf("%lf", &side);
    square = side * side;
    printf("The area of a square whose side length is %.1lf cm is %.1lf square cm.", side, square);
    return 0;
}
