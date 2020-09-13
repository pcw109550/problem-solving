#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool light[101][101];
bool visited[101][101];
int N, M;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x, y, a, b, result = 1; cin >> N >> M;
    vector<pair<int, int> > link[N + 1][N + 1] = {};
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        link[x][y].emplace_back(make_pair(a, b));
    }
    light[1][1] = true;
    visited[1][1] = true;
    queue<pair<int, int> > Q;
    Q.push({1, 1});
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (auto near : link[current.first][current.second]) {
            if (!light[near.first][near.second]) {
                result++;
                light[near.first][near.second] = true;
            }
            if (!visited[near.first][near.second]) {
                for (int dir = 0; dir < 4; dir++) {
                    int X = near.first + dx[dir];
                    int Y = near.second + dy[dir];
                    if (X < 1 || Y < 1 || X > N || Y > N)
                        continue;
                    if (visited[X][Y]) {
                        visited[near.first][near.second] = true;             
                        Q.push(near);
                        break;
                    }
                }
            }
        }
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir];
            int Y = current.second + dy[dir];
            if (X < 1 || Y < 1 || X > N || Y > N)
                continue;
            if (light[X][Y] && !visited[X][Y]) {
                Q.push({X, Y});
                visited[X][Y] = true;
            }
        }
    }
    cout << result;
}