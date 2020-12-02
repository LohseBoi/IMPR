#include<stdio.h>
#include<stdlib.h>

typedef struct card {
    u_int8_t joker, color, value;
} Card;

void generate_deck(Card*);
void print_deck(Card*);
int cmpJ(const void*, const void*);
int cmpC(const void*, const void*);
int cmpV(const void*, const void*);

int main(void) {
    Card deck[55];
    
    generate_deck(deck);
    printf("\nBefore sorting:\n");
    print_deck(deck);

    /* Using qsort to sort the cards, first in value, then in color, and finally if it is a joker or not */
    qsort(deck, 55, sizeof(Card), cmpV);
    qsort(deck, 55, sizeof(Card), cmpC);
    qsort(deck, 55, sizeof(Card), cmpJ);

    printf("\n\nAfter sorting:\n");
    print_deck(deck);
    return 0;
}

/* Generates a deck randomly */
void generate_deck(Card* deck) {
    int i = 0,
        colCount[4] = {0,0,0,0},
        valCount[4][13],
        jokeCount = 0;

    for (; i < 4; i++){
        int j = 0;
        for (; j < 13; j++)
            valCount[i][j] = 0;
    }

    for (i = 0; i < 55; i++) {
        Card temp;
        
        temp.joker = 0;
        if (jokeCount < 3) {
            temp.joker = rand() % 2;

            if (temp.joker == 1) {
                jokeCount++;
                deck[i] = temp;
                continue;
            }
        }
    
        do {
        temp.color = rand() % 4;
        } while (colCount[temp.color] >= 13);
        colCount[temp.color]++;

        do {
        temp.value = (rand() % 13) + 2;
        } while (valCount[temp.color][temp.value-2] == 1);
        valCount[temp.color][temp.value-2] = 1;
        
        deck[i] = temp;
    }
}

void print_deck(Card* deck) {
    int i = 0;
    for (; i < 55; i++) {
        printf("Card nr. %2d: ", i+1);
        if (deck[i].joker == 1) {
            printf("JOKER!!!\n");
            continue;
        }

        switch (deck[i].color) {
            case 0:
                printf("Clubs -");
                break;
            case 1:
                printf("Diamonds -");
                break;
            case 2:
                printf("Hearts -");
                break;
            case 3:
                printf("Spades -");
                break;
            default:
                /* Do nothing */
                break;
        }

        switch(deck[i].value) {
            case 11:
                printf(" Jack\n");
                break;
            case 12:
                printf(" Queen\n");
                break;
            case 13:
                printf(" King\n");
                break;
            case 14:
                printf(" Ace\n");
                break;
            default:
                printf(" %d\n", deck[i].value);
                break;
        }
    }
}

int cmpJ(const void* a, const void* b) {
    Card *CardA = (Card *)a;
    Card *CardB = (Card *)b;
    return ( CardA->joker - CardB->joker );
}

int cmpC(const void* a, const void* b) {
    Card *CardA = (Card *)a;
    Card *CardB = (Card *)b;
    return ( CardA->color - CardB->color );
}

int cmpV(const void* a, const void* b) {
    Card *CardA = (Card *)a;
    Card *CardB = (Card *)b;
    return ( CardA->value - CardB->value );
}
