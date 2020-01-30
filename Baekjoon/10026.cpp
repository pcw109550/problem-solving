#include <bits/stdc++.h>
using namespace std;

void debug(int *input, int N) {
    printf("\n");
    for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             printf("%d ", *(input + i * N + j));
         }
         printf("\n");
    }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int N; scanf("%d", &N); int input[N][N] = {}; int input2[N][N] = {};
    char temp[N + 1] = {};
    for (int i = 0; i < N; i++) {
        scanf("%s", &temp);
        for (int j = 0; j < N; j++) {
            if (temp[j] == 'R') { input[i][j] = 0; }
            if (temp[j] == 'G') { input[i][j] = 1; }
            if (temp[j] == 'R' || temp[j] == 'G') {input2[i][j] = 0;}
            if (temp[j] == 'B') { input[i][j] = 2; input2[i][j] = 1;}
        }
    }
    queue<pair<int, int>> Q; int result1 = 0, color, count = 3;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (input[i][j] == 0 || input[i][j] == 1 || input[i][j] == 2) {
                color = input[i][j];
                Q.push({i, j}); input[i][j] = ++count;
                while (!Q.empty()) {
                    pair<int, int> current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir];
                        int Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
                        if (input[X][Y] == color) {
                            Q.push({X, Y}); input[X][Y] = count;
                        }
                    }
                }
                //debug((int *)input, N);
            }
        }
    }
    result1 = count - 3;

    queue<pair<int, int>> Q2; int result2 = 0; count = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (input2[i][j] == 0 || input2[i][j] == 1) {
                color = input2[i][j];
                Q.push({i, j}); input2[i][j] = ++count;
                while (!Q.empty()) {
                    pair<int, int> current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir];
                        int Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
                        if (input2[X][Y] == color) {
                            Q.push({X, Y}); input2[X][Y] = count;
                        }
                    }
                }
            }
        }
    }
    result2 = count - 2;
    cout << result1 << " " << result2;
}