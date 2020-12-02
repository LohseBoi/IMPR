#include<stdio.h>

int main (void) {
    int x, y; 
    
    do {        /* starter mit do-while loop */
        printf("Input two positive integers: ");
        scanf("%d %d", &x, &y);
        
        if (x <= 0 || y <= 0)  /* tjekker om inputtet er positivt, hvis ikke så breaker den loopet, og returner */
            break;

        int big = x >= y ? x : y;  /* Separere mine 2 tal i størst og mindst */
        int small = x < y ? x : y;

        while (small != 0)  /* while-loop som finder divisorern, som vist på videoen */
        {
            int res = big % small;
            big = small;
            small = res;
        }

        printf("\nThe biggest divisor for %d and %d is %d\n", x, y, big);  /* printer svaret */
    } while (!(x <= 0 || y <= 0));  /* kunne også lave dette loop som et while-loop, hvor den altid vil køre indtil den breaker (while(1)) */  
    
    return 0;
}
