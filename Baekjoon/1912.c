#include <stdio.h>

int main() {
    int max = -1, acc = 0, T, temp; scanf("%d", &T); int pos = 0, negmax = -1001;
    for (int i = 0; i < T; i++) {
        scanf("%d", &temp);
        if (temp < 0) {
            if (negmax < temp) { negmax = temp; }
            if (max < acc) { max = acc; } acc = 0;
        } else {
            pos = 1;
            acc += temp;
        }
    }
    if (pos == 1) { if (max < acc) { max = acc; } }
    else { max = negmax; }
    printf("%d", max);
    // WRONG..
}