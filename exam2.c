/* Thomas Krogh Lohse
 * tlohse20@student.aau.dk
 * Group A.306
 * Datalogi (Computer Science)
 */

#include<stdio.h>
#include<stdlib.h>

void play_game(int);
void roll_multiple_dies(int*, int);
int check_section(int*, int, int);
int pairs(int*, int, int);
int kind(int*, int);
int straights(int*, int);
void print_section(int*, int, char[], int, int);


int main(void) {
    int n = 0;
 
    /* Takes the input from the user, and starts the game with that many dies. If input lower than 5, exit and program stops */
    printf("Input number of dice you want to play with (at least 5, anything lower and the game quits): ");
    scanf(" %d", &n);
    while (n >= 5) {
        play_game(n);
        printf("\nInput number of dice you want to play with (at least 5, anything lower and the game quits): ");
        scanf(" %d", &n);
    }

    return 0;
}

/* The function thats plays the game */
void play_game(int n) {
    /* Variables needed ('sum'-variable, 'n' dies and a char-array for the name of each section */
    int sum = 0;
    int* dice = malloc(n * sizeof(int));
    char title[15][16] = {"1's", "2's", "3's", "4's", "5's", "6's", "One Pair", "Two Pairs",
                          "Three of a Kind", "Four of a Kind", "Small Straight", "Large Straight",
                          "Full House", "Change", "YATZY!"};

    /* This loop is basiacally the game. 
     * First there is a roll to get random numbers, then it calculates the points received, and then prints it, along with the total.
     */
    int i = 1;
    for (; i < 16; i++) {
        roll_multiple_dies(dice, n);
        int temp = check_section(dice, i, n);
        sum += temp;
        print_section(dice, n, title[i-1], temp, sum);

        /* This part adds and prints 50 points if you have at least 63 points after turn 6 (A yatzy-rule)
         * It first adds the 50 points, then prints the text, and then some spaces to make the next part allign with the rest
         * There is added 2 spaces foreach dice above 9, since the first string is 18 spaces wide.
         * It is 2 spaces since printing 1 number is 2 spaces wide (1 for the number, and 1 for a space)
         * This makes the last print allign with the other prints for the game, except for when there is less than 9 dies, then it will not be possible with this string.
         */
        if (i == 6 && sum >= 63) {
            sum += 50;
            printf("\nBonus for having at least 63 points ");
            int j = 0;
            while (j < n-9){
                printf("  ");
                j++;
            }
            printf("| Points recieved: %2d | Points in total: %3d\n\n", 50, sum);
        }
    }

    free(dice);
}

/* Rolls 'n'-number of random numbers, takes the modulo to make sure the number is between - and 5, then adds 1 to make it match a dice */
void roll_multiple_dies(int* dice, int n) {
    int i = 0;
    for (; i < n; i++) {
        *(dice+i) = rand() % 6 + 1;
    }
}

int check_section(int* dice, int section, int n) {
    /* Variables I use in this function is iterated and declared here:
     * 'res' is what it returns, which is the points recieved on this roll
     * 'i' is for loops
     * 'count' is the array where i count how many of each eye there is. E.g if you roll 3 1's, the value in count[0] will be 3.
     */
    int res = 0,
        i = 0,
        count[6] = {0,0,0,0,0,0};
    
    /* Loop for counting. Counts 1 up in the 'count'-array */
    for (;i < n; i++)
        count[*(dice+i) - 1]++;
    
    /* Here I use a swicth-case-statement to determine which function to use, stated from my 'section' variable */
    i = 0;
    switch (section) { /* 1's to 6's */
        case 1: case 2: case 3: case 4: case 5: case 6: 
            res = section * count[section - 1];
            break;

        case 7: case 8: /* Pairs */
            res = pairs(count, section-6, 0); /* 0 as argument for the 'not', since it can take every number */
            break;

        case 9: case 10: /* Three/Four of a Kind */
            res = kind(count, section-6);
            break;

        case 11: case 12: /* Small/Large Straight */
            res = straights(count, section - 11);
            break;

        case 13: /* Full House */
            res = kind(count, 3);
            res += pairs(count, 1, res/3);
            if (res == kind(count, 3)) /* If res has not changed since it found the 3 of a kind, it has not met the conditions for a 'Full House' (A-A-A-B-B) */
                res = 0;
            break;

        case 14: /* Chance */
            for (i = 5; i >= 0; i--) {
                res += (i+1) * count[i];
            }
            break;

        case 15: /* Yatzy */
            for (; i < 6; i++) {
                if (count[i] >= 5) {
                    res = 50;
                    break;
                }
            }
            break;

        default:
            /* Do nothing */ 
            break;
    }

    return res;
}

/* Searches for num pairs. Foreach pair it finds, it adds them to the 'temp'-vairable, and counts 'num' 1 down. When 'num' = 0, it returns 'temp'.
 * If 'num' never hits 0, it means the number of pairs it was supposed to find, was never found, and then it returns 0.
 * The 'not'-variable is for the 'Full House'-part above, so it knows not to take this number, since it has been taken ('Full House' = 'A-A-A-B-B).
 */
int pairs(int* count, int num, int not) {
    int temp = 0,
        i = 5;

    for (; i >= 0; i--) {
        if (count[i] >= 2 && i+1 != not) {
            temp += (i+1) * 2;
            num--;
        }
        if (num == 0)
            return temp;
    }
    
    return 0;
}

/* Checks to see if there is 'num'-number of any eyes. it starts with 6 and goes downwards. 
 * It will return the value, if the condition is meet, otherwise it will return 0, since there was not 'num'-number of any eyes
 */
int kind(int* count, int num) {
    int i = 5;
    for (; i >= 0; i--) {
        if (count[i] >= num)
            return (i+1) * num;
    }

    return 0;
}

/* Checks to see if there is a straight from start and 5 eyes ahead (e.g '1-2-3-4-5' or '2-3-4-5-6'). 
 * It adds the numbers up, unless there is just 1 instance where there is not a dice with this eye, then it returns 0.
 */
int straights(int* count, int start) {
    int temp = 0,
        i;

    for (i = start; i < start + 5; i++) {
        if (count[i] == 0)
            return 0;

        temp += i+1;
    }

    return temp;
}

/* Here is my print-function.
 * I could just send what section to print as an integer, and make a switch-case-statement to print the section-name, but I chose to just make a string array and pass an elemnt as an argument, to save coding-lines.
 * It starts with printing what section we are in (One Pair, Two Pairs, etc.), and then prints the dice-roll. Finally it prints how many points has been recieved in this turn, along eith how many points there is in total.
 */
void print_section(int* dice, int n, char section[], int temp, int sum) {
    printf("%-15s\t  ", section);

    int i = 0;
    for (; i < n; i++)
        printf("%d ", *(dice+i));

    printf("| Points recieved: %2d | Points in total: %3d\n", temp, sum);
}
