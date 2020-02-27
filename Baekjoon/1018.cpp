#include <bits/stdc++.h>
using namespace std;
int N, M; char input[50][50];

int scanner(int x, int y) {
    int output = 0; bool flip = false; char color[2] = {'B', 'W'};
    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            output += input[i][j] == color[flip];
            flip = !flip;
        }
        flip = !flip;
    }
    return min(64 - output, output);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int result = 1 << 30; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
        }
    }
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            result = min(scanner(i, j), result);
        }
    }
    cout << result;
}