/*
Write a program that displays the multiplication table for numbers 0 to 9.
*/
#include<stdio.h>

int main(void) {
    int num;
    do {
    printf("Write the number you want to see the multiplication table of (MUST me a number between 1 and 9):\n");
    scanf("%d", &num);
    } while (num > 9 || num < 1);

    printf("---------------------\n");
    for(int i = 1; i < 11; i++)
        printf("%d * %d = %d\n", num, i, num*i);
    printf("---------------------\n");
    return 0;
}
