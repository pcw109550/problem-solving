#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, temp, result = 1 << 30;
    cin >> N >> M;
    bool Map[N][N] = {};
    vector<pair<int, int> > virus_pos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == 0) {
                Map[i][j] = true;
            } else if (temp == 1) {
                Map[i][j] = false;
            } else if (temp == 2) {
                Map[i][j] = true;
                virus_pos.push_back({i, j});
            } else {
                assert(false);
            }
        }
    }
    bool ind[virus_pos.size()] = {};
    for (int i = 0; i < M; i++)
        ind[i] = true;
    int cnt = 0;
    do {
        bool visited[N][N] = {}; int distance[N][N] = {};
        queue<pair<int, int> > Q;
        for (int i = 0; i < virus_pos.size(); i++)
            if (ind[i]) {
                int X = virus_pos[i].first;
                int Y = virus_pos[i].second;
                visited[X][Y] = true;
                Q.push({X, Y});
            }
        while (!Q.empty()) {
            auto current = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int X = current.first + dx[dir];
                int Y = current.second + dy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= N || !Map[X][Y])
                    continue;
                if (!visited[X][Y]) {
                    visited[X][Y] = true;
                    distance[X][Y] = distance[current.first][current.second] + 1;
                    Q.push({X, Y});
                } else {
                    if (distance[X][Y] > distance[current.first][current.second] + 1) {
                        distance[X][Y] = distance[current.first][current.second] + 1;
                        Q.push({X, Y});
                    }
                }
            }   
        }
        int Max = 0;
        bool avail = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && Map[i][j])
                    avail = false;
                Max = max(Max, distance[i][j]);
            }
        }
        if (avail) {        
            bool revert = true;
            while (Max > 0 && revert) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (Max == distance[i][j]) {
                            if (find(virus_pos.begin(), virus_pos.end(), make_pair(i, j)) == virus_pos.end())
                                revert = false;
                        }
                    }
                }
                if (revert)
                    Max--;
            }
            result = min(result, Max);
        }
    } while (prev_permutation(ind, ind + virus_pos.size()));
    cout << (result == 1 << 30 ? -1 : result);
}