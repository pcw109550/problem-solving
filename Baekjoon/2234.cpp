#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, cnt = 0, Max = -1;
    vector<int> sizes;
    cin >> M >> N;
    int Map[N][M] = {};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Map[i][j];

    bool visited[N][M] = {};
    int marked[N][M] = {};
    queue<pair<int, int> > Q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (visited[i][j])
                continue;
            int size = 1;
            visited[i][j] = true;
            marked[i][j] = cnt;
            Q.push({i, j});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    if ((1 << dir) & Map[current.first][current.second])
                        continue;
                    int X = current.first + dx[dir];
                    int Y = current.second + dy[dir];
                    if (!visited[X][Y]) {
                        visited[X][Y] = true;
                        marked[X][Y] = cnt;
                        size++;
                        Q.push({X, Y});
                    }
                }
            }
            cnt++;
            sizes.push_back(size);
        }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            for (int dir = 0; dir < 4; dir++) {
                int X = i + dx[dir];
                int Y = j + dy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= M)
                    continue;
                if (marked[i][j] == marked[X][Y])
                    continue;
                int merged = sizes[marked[i][j]] + sizes[marked[X][Y]];
                Max = max(Max, merged);
            }
        }
    int max_size = *max_element(sizes.begin(), sizes.end());
    cout << cnt << '\n' << max_size << '\n' << Max << '\n';
}   