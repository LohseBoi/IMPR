#include<stdio.h>
#include<math.h>

#define FIRST first_root(dis, a, b)
#define SECOND second_root(dis, a, b)

double discriminant(double a, double b, double c);
double first_root(double dis, double a, double b);
double second_root(double dis, double a, double b);
void solve_quadratic_equation(double a, double b, double c);

int main(void) {
    double a, b, c;

    printf("Given an equation ax^2 + bx + c = 0, input the variables (a, b and c) to find the roots:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    solve_quadratic_equation(a, b, c);

    return 0;
}

void solve_quadratic_equation(double a, double b, double c) {
    double dis = discriminant(a, b, c);
    if(dis < 0)
        printf("no roots\n");
    else if(dis == 1.0) 
        printf("One root: %.2lf\n", FIRST);
    else
        printf("First root: %.2lf | Second root: %.2lf\n", FIRST, SECOND);
 
}
double discriminant(double a, double b, double c) {
    return b * b - 4.0 * a * c;
}

double first_root(double dis, double a, double b) {
    if(dis == 1.0)
        return -b/(2.0*a);
    else
        return -b + sqrt(dis)/(2.0*a);
}

double second_root(double dis, double a, double b) {   
    return -b - sqrt(dis)/(2.0*a);
}
