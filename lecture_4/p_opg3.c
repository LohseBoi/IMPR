/*
Write a program to display a centimeters-to-inches conversion table. The smallest and largest number of centimeters in the table are input values. Your table should give conversions in 10-centimeter intervals. One centimeter equals 0.3937 inch.
*/

#include<stdio.h>

int main(void) {
    const double convertConst = 0.3937;
    int n, m;

    printf("Input an interval to convert centimeters to inches (n m)");
    scanf("%d %d", &n, &m);

    for(; n < m; n+=10)
        printf("%d cm is %.4lf inches\n", n, n*convertConst);

    return 0;
}
