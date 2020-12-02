#include<stdio.h>
#include<stdlib.h>

int modulus(int, int);
int quotient(int, int);

int main (void) {
    
    int t1 = 32,
        t2 = 6;
    printf("%d mod %d = %d\n", t1, t2, modulus(t1, t2));
    printf("%d div %d = %d\n", t1, t2, quotient(t1, t2));
    return 0;
}


int quotient(int dividend, int divisor) {
    dividend -= divisor;
    if (dividend <= 0)
        return 0;
    else
        return 1 + quotient(dividend, divisor);
}

int modulus(int dividend, int divisor) {
    dividend -= divisor;
    if (dividend < 0)
        return dividend + divisor;
    else if (dividend == 0)
        return 0;
    else
        modulus(dividend, divisor);
}
