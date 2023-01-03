#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
    printf("Task 2, variant 7\n");

    double a, z1, z2;

    printf("Please, enter a: ");
    while (scanf("%lf", &a) != 1) {
        printf("Oops, you enter smth wrong!\n");
        printf("Please, enter a: ");
        fflush(stdin);
    }
    
    z1 = pow(cos((3.0/8)*M_PI - (a/4)), 2) - pow(cos((11.0/8)*M_PI + (a/4)), 2);
    z2 = (M_SQRT2/2)*sin(a/2);
    printf("Z1 = %.7f\n", z1);
    printf("Z2 = %.7f\n", z2);
    
    return 0;
}