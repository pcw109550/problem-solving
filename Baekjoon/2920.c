#include <stdio.h>

int main(void) {
    int input[8] = {}; int asc = 0, des = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &input[i]);
        if (i == 0 && input[0] == 1) { asc = 1; }
        if (i != 0 && asc) { if (input[i - 1] > input[i]) { asc = 0; } }
        if (i == 0 && input[0] == 8) { des = 1; }
        if (i != 0 && des) { if (input[i - 1] < input[i]) { des = 0; } }
    }
    if (asc)      { printf("ascending"); }
    else if (des) { printf("descending"); }
    else          { printf("mixed");     }
}