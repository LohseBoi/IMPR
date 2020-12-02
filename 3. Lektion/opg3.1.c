/*
Det er ofte nyttigt at kunne afgøre, om et punkt i et koordinatsystem er placeret inden i eller udenfor en bestemt cirkel.

Skriv et program med tre doubles r, x og y.   r fortolkes som radius af en cirkel omkring punktet (0,0). x og y er koordinaterne (x, y) af et punkt.

Programmet skal afgøre om punktet (x, y) er placeret inden i cirklen, på cirkelperiferien, eller uden for cirklen. Der er altså tre tilfælde.
I bedes have tre logiske udtryk, assignet til tre logiske variable, som afspejler de tre forskellige situationer.

Kan I lave én printf med brug af betingede udtryk (?:), der udskriver 'inden i'/'uden for' og 'på' cirklen, baseret på de logiske udtryks værdi?

Hint: Det kan være svært at ramme periferien eksakt, fordi vi regner med doubles.
Derfor kan I antage at punktet er 'på periferien' hvis det er ganske tæt på periferien.
Indfør en symbolsk konstant DELTA, der fortæller hvor meget vi ønsker at kunne afvige fra et "perfect hit".
*/

#include<stdio.h>

#define CIR_LIG ((x-0)*(x-0) + (y-0)*(y-0))  //Cirklens ligning

int main (void) {
    double r = 5.0, x, y;
    
    printf("Angiv radiussen, r, på en cirkel i punktet (0,0), samt et punkt, (x, y). Skriv i formatet 'r (x,y)': ");
    scanf("%lf (%lf,%lf)", &r, &x, &y);

    //    ------Tjekker om den ligger udenfor cirkelperiferien--   ----Ellers tjekker den om den er indenfor-----    Ellers må den ligge på cirkelperiferien
    char *result = CIR_LIG > r*r ? "udenfor" : (CIR_LIG < r*r ? "indenfor" : "på" );
    printf("\nPunktet (%0.2lf,%0.2lf) ligger %s cirkelperiferien\n", x, y, result);

    return 0;
}