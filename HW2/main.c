#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
    printf("Task 2, variant 7\n");
    int iter = 5;
    double a, z1, z2;
    while (iter > 0) {
        printf("This is %d iteration\n", 6 - iter);
        printf("Please, enter a: ");
        while (scanf("%lf", &a) != 1) {
            printf("Oops, you enter smth wrong!\n");
            printf("Please, enter a: ");
            fflush(stdin);
        }
        z1 = pow(cos((3.0/8)*M_PI - (a/4)), 2) - pow(cos((11.0/8)*M_PI + (a/4)), 2)/*((1 + cos(2*((3/8)*M_PI - (a/4))))/2) - ((1 + cos(2*((11/8)*M_PI + (a/4))))/2)*/;
        z2 = (M_SQRT2/2)*(a/2);
        printf("Z1 = %.7f\n", z1);
        printf("Z2 = %.7f\n", z2);
        iter--;
    }

    return 0;
}