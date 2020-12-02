/*
 * Thomas Krogh Lohse 
 * tlohse20@student.aau.dk
 * Gruppe A.306
 * Datalogi 
 */
#include<stdio.h>
#include<math.h>

double run_calculator();
void scan_data(char *operator, double *operand); 
void do_next_op(char *operator, double *operand, double *result); 
void print_help(void);

int main(void) {
    /* Prints the end-result */
    printf("\nEnd result of the accumulator = %.2lf\n", run_calculator());
    return 0;
}

double run_calculator() {
    print_help(); /* Starts with printing the help-menu, showing all commands in the program */
    /* Instantiates and declares variables */
    char operator;
    double operand, result = 0.0;
    do { /* Iteratively asks the user to give an input, and acts accordingly */
    printf("Accumulator so far = %.2lf\n\n", result);
    scan_data(&operator, &operand);
    do_next_op(&operator, &operand, &result);
    } while(operator != 'q' && operator != 'Q'); /* Keeps asking untill the 'Quit'-input is typed */

    return result;
}

void scan_data(char *operator, double *operand) {
    printf("Enter an operator and, possibly, an operand: ");
    scanf(" %c", operator); /* Scans input as the operator */
    switch(*operator) {  /* If it is an operator that needs an operand, it continues to the next scanf, which takes the input as the operand */
        case '+': case '-': case '*': case '/': case '^':
            break;
        default:
            return;
    }
    scanf("%lf", operand);
}

void do_next_op(char *operator, double *operand, double *result) {
    int i;
    switch(*operator) {  /* Executes the commands given to the specific operators */
        case '+':
            *result += *operand;
            break;
        case '-':
            *result -= *operand;
            break;
        case '*':
            *result *= *operand;
            break;
        case '/':
            if (*operand != 0)
                *result /= *operand;
            break;
        case '^':
            for(i = 0; i < *operand; i++)
                *result *= *result;
            break;

        case '#':
            if (*result >= 0)
                *result = sqrt(*result);
            break;
        case '%':
            *result = *result * (-1);
            break;
        case '!':
            if(*result != 0)
                *result = 1 / *result;
            break;
        case 'q': case 'Q':
            printf("\nQuitting\n");
            break;
        case 'h': case 'H':
            print_help();
            break;
        default:
            printf("\nType something valid, please.\nType 'h' for help\n");
            break;
    }
}

void print_help(void) {  /* Prints all of the commands in the program */
    printf("\nOperators in this program in no particular order:\n");
    printf("    '+ <operand>'    Adds <operand> to the accumulator\n");
    printf("    '- <operand>'    Subtracts <operand> from the accumulator\n");
    printf("    '* <operand>'    Times the accumulator with <operand>\n");
    printf("    '/ <operand>'    Divides the accumulator with <operand>\n");
    printf("    '^ <operand>'    Raise accumulator to the power of <operand>\n\n");

    printf("    '#'    Squares the accumulator\n");
    printf("    '%c'    Reverses the sign of the accumulator\n", '%');
    printf("    '!'    Divides the accumulator with 1\n\n");

    printf("    'h'    Prints this help-menu\n");
    printf("    'q'    Quits the program\n\n");
}
