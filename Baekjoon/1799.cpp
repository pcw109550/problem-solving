#include <bits/stdc++.h>
using namespace std;
bool isused1[19], isused2[19]; bool input[10][10];
int n, result;

void backtrack(int k) {
    bool temp = true;
    for (int i = 0; i < 2 * n - 1; i++) {
        temp = temp && isused1[i]; temp = temp && isused2[i];
    }
    if (temp == true) { if (result < k) { result = k; } return; }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (!isused1[x + y] && !isused2[x - y + n - 1] && input[x][y]) {
                isused1[x + y] = isused2[x - y + n - 1] = true;
                
                
                backtrack(k + 1);
                
                isused1[x + y] = isused2[x - y + n - 1] = false;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; n = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }
    for (int i = 0; i < 2 * N - 1; i++) {
        for (int j = 0; j <= i; j++) {
            int x1 = j, y1 = i - j; int x2 = j, y2 = N - 1 - i + j;
            if (0 <= x1 && x1 < N && 0 <= y1 && y1 < N) { isused1[i] |= input[x1][y1]; }
            if (0 <= x2 && x2 < N && 0 <= y2 && y2 < N) { isused2[i] |= input[x2][y2]; }
        }
    }
    for (int i = 0; i < 2 * N - 1; i++) { isused1[i] = !isused1[i]; isused2[i] = !isused2[i]; }

    //for (int i = 0; i < 2 * N - 1; i++) { cout << isused1[i] << " " << isused2[i] << "\n"; }
    backtrack(0);
    cout << result;
}