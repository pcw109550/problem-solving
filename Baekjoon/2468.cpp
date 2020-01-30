#include <bits/stdc++.h>
using namespace std;

void debug(int *input, int N) {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(input + N * i + j) << " ";
        }
        cout << "\n";
    }
}

int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); int min = 101, max = 0;
    int N; cin >> N; int input[N][N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
            if (min > input[i][j]) { min = input[i][j]; }
            if (max < input[i][j]) { max = input[i][j]; }
        }
    }
    if (min == max) { cout << 1; return 0;}
    int count = 1; int maxcnt = 0;
    for (int h = min; h < max; h++) {
        int temp[N][N] = {};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[i][j] = input[i][j] > h;
            }
        }
        queue<pair<int, int>> Q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (temp[i][j] == 1) {
                    Q.push({i, j}); temp[i][j] = ++count;
                    while (!Q.empty()) {
                        pair<int, int> current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir];
                            int Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
                            if (temp[X][Y] == 1) {
                                Q.push({X, Y}); temp[X][Y] = count;
                            }
                        }
                    }
                }
            }
        }
        if (maxcnt < count) { maxcnt = count;}
        count = 1;
        //debug((int *)&temp, N);
    }
    cout << maxcnt - 1;
}