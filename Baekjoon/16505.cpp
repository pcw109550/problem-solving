#include <bits/stdc++.h>
using namespace std;
char Map[1024][1024];
int N;

void fun(int n, int x, int y) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (i == x || j == y || i + j == n - 1) {
                Map[i][j] = '*';
            }
        }
    }
    n >>= 1;
    if (n > 1) {
        fun(n, x, y);
        fun(n, x + n, y);
        fun(n, x, y + n);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    fill(*Map, *Map + (1 << 20), ' ');
    fun(1 << N, 0, 0);
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < (1 << N) - i; j++) {
            cout << Map[i][j];
        }
        cout << '\n';
    }
}