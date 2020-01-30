#include <bits/stdc++.h>
using namespace std;
int n = 0;

void func(int a, int b, int c, int acc, char *output) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < 2 * n; x++) {
            if (y >= a && y + x + b < -1 && y - x + c <= 0 ) { *(output + x + 2 * n * y) = ' '; }
        }
    }
    if (acc == 1) { return; }
    if (acc == 0) { acc = n / 4; } else { acc /= 2; }
    if (acc != 1) {
        func(a + acc, b + 2 * acc, c - 2 * acc, acc, output);
        func(a + acc, b - 2 * acc, c + 2 * acc, acc, output);
        func(a - acc, b + 2 * acc, c + 2 * acc, acc, output);
    } else {
        func(a + 1, b + 4, c - 2, 1, output);
        func(a + 1, b - 2, c + 4, 1, output);
        func(a - 2, b + 4, c + 4, 1, output);
    }
    //func(n / 4, n / 2, - )
    /*
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < 2 * n; x++) {
            if (y >= N / 2 + N / 4 && y + x - 2 * N + N / 2 < -1 && y - x - N / 2 <= 0  ) { *(output + x + 2 * n * y) = ' '; }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < 2 * n; x++) {
            if (y >= N / 2 + N / 4 && y + x - 2 * N - N / 2 < -1 && y - x + N / 2 <= 0  ) { *(output + x + 2 * n * y) = ' '; }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < 2 * n; x++) {
            if (y >= N / 2 - N / 4 && y + x - 2 * N + N / 2 < -1 && y - x + N / 2 <= 0  ) { *(output + x + 2 * n * y) = ' '; }
        }
    }*/
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; char output[N][2 * N]; memset(output, ' ', 2 * N * N);
    if (N == 3) { cout << "  *   \n * *  \n***** \n"; return 0;}
    n = N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < 2 * N; x++) {
            if (y + x - N >= -1 && y - x + N > 0) { output[y][x] = '*'; }
        }
    }
    func(N / 2, -2 * N, 0, 0, (char *)&output);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            cout << output[i][j];
        }
        cout << '\n';
    }
}