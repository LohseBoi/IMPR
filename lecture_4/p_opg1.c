/*
Write a program segment that computes 1+2+3+...+(n-1)+n, where n is a data value. Follow the loop body with an if statement that com-pares this value to (n*(n+1))/2 and displays a message that indicates whether the values are the same or different. What message do you think will be displayed?
*/

#include<stdio.h>

int main(void) {
    int n, sum = 0;
    printf("Input an integer:\n");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        sum += i;

    if (n*(n+1)/2 == sum)
        printf("(%d*(%d+1))/2 is the same as the sum, %d", n, n, sum);
    else
        printf("(%d*(%d+1))/2 is not the same as the sum, %d", n, n, sum);

    return 0;
}
