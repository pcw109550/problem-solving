#include <stdio.h>

int main(void) {
    double A, B; scanf("%lf %lf", &A, &B);
    double result = A / B;
    printf("%.17g", result);
}