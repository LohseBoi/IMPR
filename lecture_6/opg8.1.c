/*
Definer tre forskellige enumeration typer for hhv. forret, hovedret og dessert.

Enumeration typen forret skal indholde værdier for guacamole, tarteletter, lakserulle og græskarsuppe.

Enumeration typen hovedret skal indholde værdier for gyldenkål, hakkebøf, gullash og forloren hare.

Enumeration typen dessert skal indholde værdier for pandekager med is, gulerodskage, choklademousse, og citronfromage.

Undgå dog danske bogstaver i dit C program. Det giver kun besvær!

Skriv en funktion maaltid, som vælger og udskriver én tilfældig ret i hver af de tre kategorier. Læs om "tilfældige tal" i C her.

Kald funktionen maaltid 25 gange i main, med det formål at få genereret et menukort af 25 kombinationer af forret, hovedret og dessert.

Overvej om der skal defineres flere små funktioner, som nedbryder det samlede problem i delproblemer.
*/

#include<stdio.h>
#include<stdlib.h>
void maaltid(int*);
void print_menu(int*);

enum forret {guacamole, tarteletter, lakserulle, graeskarsuppe};
enum hovedret {gyldenkaal, hakkeboef, gullash, forloren_hare};
enum dessert {pandekager_med_is, gulerodskage, choklademousse, citronfromage};

int main(void) {
    int menu[25][3];

    for(int i = 0; i < 25; i++) {
        maaltid(menu[i]);
        print_menu(menu[i]);
    }
    return 0;
}

void maaltid(int* serv) {
    serv[0] = rand() % 4;
    serv[1] = rand() % 4;
    serv[2] = rand() % 4;
}

void print_menu(int* menu) {
    printf("Forret: ");
    switch(menu[0]) {
        case 0:
            printf("Guacamole\n");
            break;
        case 1:
            printf("Tarteletter\n");
            break;
        case 2:
            printf("Lakserulle\n");
            break;
        case 3:
            printf("Græskaruppe\n");
        default:
            break;
    }
    printf("Hovedret: ");
    switch(menu[1]) {
        case 0:
            printf("Gyldenkål\n");
            break;
        case 1:
            printf("Hakkebøf\n");
            break;
        case 2:
            printf("Gullash\n");
            break;
        case 3:
            printf("Forloren hare\n");
        default:
            break;
    } 
    printf("Dessert: ");
    switch(menu[2]) {
        case 0:
            printf("Pandekager med is\n\n");
            break;
        case 1:
            printf("Gulerodskage\n\n");
            break;
        case 2:
            printf("Chokolademuse\n\n");
            break;
        case 3:
            printf("Citronfomage\n\n");        
        default:
            break;
    }
}
