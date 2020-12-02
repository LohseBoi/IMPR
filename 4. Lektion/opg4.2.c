/*
I denne opgave gives tre positive heltal m, n og k, hvor k er større end 1. Skriv et program der adderer alle heltal mellem m og n (begge inklusive) hvor i k går op.

Eksempler:

    Hvis m er 5, n er 13 og k er 3 er resultatet 6 + 9 + 12 = 27.
    Hvis m er 5, n er 10 og k er 5 er resultatet 5 + 10 = 15.
    Hvis m er 10, n er 5 og k er 3 ønsker vi at resultatet er 0, idet m er større end n.

Denne opgave stammer fra bogen C by Dissection - anvendt med tilladelse fra forlaget.
*/
#include<stdio.h>


int main(void) {
    int m, n, k, sum = 0;
    printf("Skriv 3 tal:\n    Et der sætter minumum\n    Et der sætter maksimum\n    Et der sætter tallet det skal gå op i\n");
    scanf("%d %d %d", &m, &n, &k);
    
    printf("\nSummen af alle heltal mellem %d og %d der går op i %d er ", m, n, k);
    for(;m <= n; m++) {
        if (m % k != 0)
            continue;
        else
            sum += m;
    }
    printf("%d\n", sum);
    return 0;
}
