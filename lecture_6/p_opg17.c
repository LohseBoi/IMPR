#include<stdio.h>
#include<math.h>

double trap(double, double, int, double (*)(double));
double sum(double, double, int, double (*)(double));

double g(double);
double h(double);

/* Printer kun for -2 til 2 af h(x), da det er det eneste jeg skal (tror jeg).
 * Man kan selvfølgelig bare indsætte g(x) hvis man vil, eller ændre på xa og xb
 */
int main(void) {

    int n;
    printf("Enter 'n': "); scanf(" %d", &n);
    printf("T on h(x) = %.2lf\n", trap(-2, 2, n, &h));     return 0;
}

double trap(double a, double b, int n, double (*f)(double)) {
    double h = (b-a) / n;
    double T = h/2 * (f(a) + f(b) + 2.0 * sum(a, h, n, f));
    
    return T;
}

double sum(double a, double h, int n, double (*f)(double)) {
    double result = 0;
    for (double i = 1; i < n; i += 1) {
        result += f(a + i*h);
    }
    return result;
}

double g(double x) {
    return (x*x)*sin(x);
}

double h(double x) {
    return sqrt(4.0-(x*x));
}
