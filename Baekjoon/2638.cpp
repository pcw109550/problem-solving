#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, T = 0, cnt = 0, tempcnt; cin >> N >> M;
    int Map[N][M] = {};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 1)
                cnt++;
        }
    while (cnt > 0) {
        T++;
        tempcnt = cnt;
        queue<pair<int, int> > Q;
        bool visited[N][M] = {};
        Q.push({0, 0});
        visited[0][0] = true;
        while (!Q.empty()) {
            auto current = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int X = current.first + dx[dir];
                int Y = current.second + dy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= M)
                    continue;
                if (!visited[X][Y]) {
                    if (Map[X][Y] >= 1) {
                        Map[X][Y] |= (1 << (dir + 1));
                    } else {
                        visited[X][Y] = true;
                        Q.push({X, Y});
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (Map[i][j] > 1) {
                    if (__builtin_popcount(Map[i][j]) >= 3) {
                        Map[i][j] = 0;
                        tempcnt--;                        
                    } else {
                        Map[i][j] = 1;
                    }
                }
        if (tempcnt == 0) {
            break;
        }
        cnt = tempcnt;
    }
    cout << T;
}   