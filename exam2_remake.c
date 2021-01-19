/* Thomas Krogh Lohse
 * tlohse20@student.aau.dk
 * Group A.306
 * Datalogi (Computer Science)
 */

#include<stdio.h>
#include<stdlib.h>

int play_game(int);
void roll_multiple_dies(int*, int*, int);
void count_roll(int*, int*, int);
int check_section(int*, int, int);
int singles(int*, int);
int pairs(int*, int);
int kind(int*, int);
int straights(int*, int);
int full_house(int*, int);
int chance(int*, int);
int yatzy(int*, int);
void print_section(int*, int, char[], int, int);


int main(void) {
    int n = 0;
 
    /* Takes the input from the user, and starts the game with that many dies. If input lower than 5, exit and program stops */
    printf("Input number of dice you want to play with (at least 5, anything lower and the game quits): ");
    scanf(" %d", &n);
    int ret;
    while (n >= 5) {
        ret = play_game(n);
        printf("\nInput number of dice you want to play with (at least 5, anything lower and the game quits): ");
        scanf(" %d", &n);
    }

    return ret;
}

/* The function thats plays the game */
int play_game(int n) {
    /* Variables needed ('sum'-variable, 'n' dies and a char-array for the name of each section */
    int sum = 0;
    int* dice = malloc(n * sizeof(int));
    if (dice == NULL) {
        printf("ERROR: Not enough memory. Try a lower number, or a better machine");
        return 1;
    }
    char title[15][16] = {"1's", "2's", "3's", "4's", "5's", "6's", "One Pair", "Two Pairs",
                          "Three of a Kind", "Four of a Kind", "Small Straight", "Large Straight",
                          "Full House", "Change", "YATZY!"};
    int (*sec[15]) (int*, int) = {singles, sec[0], sec[0], sec[0], sec[0], sec[0],
                                  pairs, pairs, kind, kind, straights, straights,
                                  full_house, chance, yatzy};
    int count[6];
    int i = 1;


    for (; i < 16; i++) {
        roll_multiple_dies(dice, count, n);
        //count_roll(count, dice, n);
        int temp = sec[i-1](count, i);
        //int temp = check_section(dice, i, n);
        sum += temp;
        print_section(dice, n, title[i-1], temp, sum);

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
    return 0;
}

void roll_multiple_dies(int* dice, int* count, int n) {
    int i = 0;
    for (;i < 6; i++)
        count[i] = 0;

    for (i = 0; i < n; i++) {
        *(dice+i) = rand() % 6 + 1;
        count[dice[i]-1]++;
    }

}

void count_roll(int* count, int* dice, int n) {
    int i = 0;
    for (;i < n; i++)
        count[*(dice+i) - 1]++;

}

int singles(int* count, int num) {
    return num*count[num-1];
}

int pairs(int* count, int num) {
    int temp = 0,
        i = 5;
    num -= 6;

    for (; i >= 0; i--) {
        if (count[i] >= 2) {
            temp += (i+1) * 2;
            num--;
        }
        if (num == 0)
            return temp;
    }
    
    return 0;
}

int kind(int* count, int num) {
    int i = 5;
    num -= 6;
    for (; i >= 0; i--) {
        if (count[i] >= num)
            return (i+1) * num;
    }

    return 0;
}

int straights(int* count, int start) {
    int temp = 0,
        i;
    start -= 11;

    for (i = start; i < start + 5; i++) {
        if (count[i] == 0)
            return 0;

        temp += i+1;
    }

    return temp;
}

int full_house(int* count, int num) {
    num = kind(count, 3+6);

    if (!num)
        return 0;
    //pairs
    int i = 5;
    for (; i >= 0; i--) {
        if (count[i] >= 2 && i+1 != num/3) {
            num += ((i+1) * 2);
            return num;
        }
    }
    

    return 0;
}

int chance(int* count, int num) {
    int i, res = 0;
    for (i = 5; i >= 0; i--) {
                res += (i+1) * count[i];
            }

    return res;
}

int yatzy(int* count, int num) {
    int i = 0;
    for (; i < 6; i++) {
        if (count[i] >= 5)
            return 50;
        }

    return 0;
}

void print_section(int* dice, int n, char section[], int temp, int sum) {
    printf("%-15s\t  ", section);

    int i = 0;
    for (; i < n; i++)
        printf("%d ", *(dice+i));

    printf("| Points recieved: %2d | Points in total: %3d\n", temp, sum);
}
