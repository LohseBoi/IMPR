/* Thomas Krogh Lohse
 * tlohse20@student.aau.dk
 * Group A.306
 * Datalogi (Computer Science)
 */

#include<stdio.h>
#include<stdlib.h>

void Dice_Roll(int*, int);
void Sort(int*, int);
int Check_Section(int*, int, int);
void Print_Section(int*, int, int, int, int);

int main(void) {
    int n = 0;
 
    do {
        int sum = 0;

        do {
            printf("Input number of dice you want to play with (at least 5): ");
            scanf(" %d", &n);
        } while (n < 5);

        int* dice = malloc(n * sizeof(int));
    
        int i = 1;
        for (; i < 16; i++) {
            Dice_Roll(dice, n);
            int temp = Check_Section(dice, i, n);
            sum += temp;
            Print_Section(dice, n, i, temp, sum);

            if (i == 6 && sum >= 23) {
                sum += 50;
                printf("\nBonus for having at least 63 points   | Points recieved: %2d | Points in total: %3d\n\n", 50, sum);
            }
        }

        free(dice);
        printf("\n\nIf you want play again, input '1'. If you want to quit, input '0': ");
        scanf(" %d", &n);
    } while (n == 1);
    return 0;
}

void Dice_Roll(int* dice, int n) {
    int i = 0;
    for (; i < n; i++) {
        *(dice+i) = rand() % 6 + 1;
    }
    Sort(dice, n);
}

void Sort(int* dice, int n) {
    int i = 0;

    for (; i < n - 1; i++) {
        int j = 0;
        for (; j < n - i - 1; j++) {
            if (*(dice+j) > *(dice+j+1)) {
                int temp = *(dice+j);
                *(dice+j) = *(dice+j+1);
                *(dice+j+1) = temp;
            }
        }
    }

}

int Check_Section(int * dice, int section, int n) {
    int res = 0,
        i = 0,
        var = 0;
    switch (section) {
        /* Rolls between 1 and 6 They just seek for the section number. The way it does is the same, it checks for section+1 in the list */
        case 1: case 2: case 3: case 4: case 5: case 6: 
            for (; i < n; i++) {
                if (*(dice+i) == section)
                    var++;
            }
            res = var * section;
            break;

        case 7: case 8: /* Pairs */
            var = section - 8;
            for (i = n - 1; i > 0; i--) {
                if (*(dice+i) == *(dice+i-1) && *(dice+i) != var) {
                    res += *(dice+i) * 2;
                    if (var != 0)
                        break;
                    var = *(dice+i);
                }
            }
            if (res <= var * 2)
                res = 0;
            break;

        case 9: case 10: /* Three/Four of a Kind */
            var = 2 + (section - 9);
            for (i = n - 1 ; i >= var; i--) {
                if (*(dice+i) == *(dice+i-var)) {
                    res = *(dice+i) * (var + 1);
                    break;
                }
            }
            break;

        case 11: case 12: /* Small/Large Straight */
            var = section - 10;
            for(; i < n && var < section - 5; i++) {
                if (dice[i]==var)
                    res += var++;
            }
            if (var < section - 5)
                res = 0;
            break;

        case 13: /* Full House */
            for (i = n - 1; i > 0; i--) {
                int f = res > 0 ? 1 : 2;
                if (*(dice+i) == *(dice+i-f) && *(dice+i) != var) {
                    res += *(dice+i) * (f+1);
                    f--;
                    if (var != 0)
                        break;
                    var = *(dice+i);
                    i = n;
                }
            }
            if (res <= var * 3)
                res = 0;

            break;

        case 14: /* Chance */
            for (i = n - 1; i > n - 6; i--) {
                res += *(dice+i);
            }
            break;

        case 15: /* Yatzy */
            for (i = n - 1 ; i >= var; i--) {
                if (*(dice+i) == *(dice+i-4)) {
                    res = 50;
                    break;
                }
            }

            break;
        default:

            break;
    }
    return res;
}

void Print_Section(int* dice, int n, int section, int temp, int sum) {
    
    switch (section) {
        case 1: case 2: case 3: case 4: case 5: case 6: 
            printf("%d's             | ", section);
            break;
        case 7:
            printf("One Pair        | ");
            break;
        case 8:
            printf("Two Pairs       | ");
            break;
        case 9:
            printf("Tree of a Kind  | ");
            break;
        case 10:
            printf("Four of a Kind  | ");
            break;
        case 11:
            printf("Small Straight  | ");
            break;
        case 12:
            printf("Large Straight  | ");
            break;
        case 13:
            printf("Full House      | ");
            break;
        case 14:
            printf("Chance          | ");
            break;
        case 15: /* Prints for yatzy */
            printf("YATZY!          | ");
            break;
        default:

            break;
    }
    int i = 0;
    for (; i < n; i++)
        printf("%d ", *(dice+i));
    printf("| Points recieved: %2d | Points in total: %3d\n", temp, sum);
}


