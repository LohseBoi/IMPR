#include <stdio.h>

int main(void)
{
    int num;
    printf("Hvilket fib-tal vil du ha? ");
    scanf("%i", &num);
    printf("\n\n%i", fib(num, 1, 0));
    return 0;
}

int fib(int ite, int big, int small)
{
    if (ite == 0)
        return big;
    
    return fib(ite-1, big + small, big);
}