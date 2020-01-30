#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void debug(int *input, int N, int M) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
           cout << *(input + i * N + j) << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    int M, N, K; cin >> M >> N >> K; int input[M][N] = {};
    int x1, y1, x2, y2;
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                input[y][x] = 1;
            }
        }
    }
    int count = 1; list<int> result; int size = 1;
    queue<pair<int, int>> Q;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (input[i][j] == 0) {
                Q.push({i, j}); input[i][j] = count + 1;
                while (!Q.empty()) {
                    pair<int, int> current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir]; int Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N) { continue; }
                        if (input[X][Y] == 0) {
                            input[X][Y] = count + 1; Q.push({X, Y}); size++;
                        }
                    }
                }
                count++; result.push_back(size);
                size = 1;
            }
        }
    }
    cout << count - 1 << "\n";
    result.sort();
    auto it = result.begin();
    int n = result.size();
    for (int i = 0; i < n; i++) {
        cout << *(it++);
        if (i != n - 1) { cout << " "; }   
    }
}