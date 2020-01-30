#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void debug(int *input, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << *(input + i * M + j) << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, N; cin >> M >> N; int input[N][M] = {};
    int notriped = 0, notomato = 0, tomato = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
            if (input[i][j] == 0) { notriped++; }
            if (input[i][j] == -1) { notomato++; }
            if (input[i][j] == 1) { tomato++; }
        }
    }
    if (tomato + notomato == N * M) { cout << 0; return 0;}
    queue<pair<int, int>> Q; bool visited[N][M] = {}; int count = 0; int touched = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (input[i][j] == 1 && !visited[i][j]) {
                Q.push({i, j}); visited[i][j] = true; touched++;
                while (!Q.empty()) {
                    pair<int, int> current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir]; int Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                        if (input[X][Y] == -1) { continue; }
                        if (!visited[X][Y] && input[X][Y] == 1) {
                            visited[X][Y] = true; Q.push({X, Y}); 
                        }
                        if (input[X][Y] == 0) {
                            visited[X][Y] = true; input[X][Y] = input[current.first][current.second] + 1;
                            Q.push({X, Y}); count++;
                            continue;
                        }
                        if (visited[X][Y] && input[X][Y] > input[current.first][current.second] + 1) {
                            input[X][Y] = input[current.first][current.second] + 1;
                            Q.push({X, Y});
                            continue;
                        }
                    }
                }
                if (count != notriped && touched == tomato) { cout << -1; return 0; }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { 
            if (result < input[i][j]) { result = input[i][j]; }
            if (input[i][j] == 0) { cout << -1; return 0; }
        }
    }
    cout << result - 1;
}