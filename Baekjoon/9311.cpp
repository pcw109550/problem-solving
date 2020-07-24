#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void task() {
    int R, C;
    char temp;
    cin >> R >> C;
    vector<pair<int, int> > goals;
    pair<int, int> start;
    bool map[R][C] = {};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> temp;
            if (temp == 'X') {
                map[i][j] = true;
            } else if (temp == 'S') {
                start = {i, j};
            } else if (temp == 'G') {
                goals.push_back({i, j});
            }
        }
    }
    bool visited[R][C] = {};
    int distance[R][C] = {};
    queue<pair<int, int> > Q;
    visited[start.first][start.second] = true;
    Q.push(start);
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir];
            int Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= R || Y >= C)  
                continue;
            if (!visited[X][Y] && !map[X][Y]) {
                visited[X][Y] = true;
                distance[X][Y] = distance[current.first][current.second] + 1;
                Q.push({X, Y});
            }
        }
    }
    int Min = 1 << 30;
    for (auto goal: goals) {
        int X = goal.first;
        int Y = goal.second;
        if (visited[X][Y])
            Min = min(Min, distance[X][Y]);
    }
    if (Min == 1 << 30)
        cout << "No Exit\n";
    else
        cout << "Shortest Path: " << Min << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        task();
}