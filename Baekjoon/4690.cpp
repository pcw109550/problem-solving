#include <bits/stdc++.h>
using namespace std;

inline int cube(int x) { return x * x * x; }

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            for (int c = b; c <= 100; c++) {
                for (int d = c; d <= 100; d++) {
                    if (cube(a) == cube(b) + cube(c) + cube(d)) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
}