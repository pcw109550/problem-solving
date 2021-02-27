#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int Map[100][100];
int N;
int result = INT_MAX;
queue<pair<int, int> > Q;
vector<vector<pair<int, int> > > border;

inline bool is_border(pair<int, int> coord) {
    for (int dir = 0; dir < 4; dir++) {
        int X = coord.first + dx[dir];
        int Y = coord.second + dy[dir];
        if (X < 0 || Y < 0 || X >= N || Y >= N)
            continue;
        if (Map[X][Y] == 0)
            return true;
    }
    return false;
}

inline void insert_if_border(pair<int, int> coord) {
    if (is_border(coord))
        border.back().push_back(coord);
}

inline int get_distance(int idx) {
    bool visited[100][100] = {};
    int distance[100][100] = {};
    Q = queue<pair<int, int> >();
    for (auto coord : border[idx - 1]) {
        Q.push(coord);
        visited[coord.first][coord.second] = true;
    }
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir];
            int Y = current.second + dy[dir];
            if (distance[current.first][current.second] >= result)
                return INT_MAX; // optimization
            if (X < 0 || Y < 0 || X >= N || Y >= N)
                continue;
            if (Map[X][Y] > 0 && Map[X][Y] != idx) 
                return distance[current.first][current.second];
            if (!visited[X][Y] && !Map[X][Y]) {
                visited[X][Y] = true;
                distance[X][Y] = distance[current.first][current.second] + 1;
                Q.push({X, Y});
            }
        }
    }
    return INT_MAX;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    // O(N ** 2)
    cin >> N;
    int num_island = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Map[i][j];
    bool visited[100][100] = {};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || !Map[i][j])
                continue;
            num_island++;
            border.push_back(vector<pair<int, int> >());
            Q.push({i, j}); visited[i][j] = true;
            Map[i][j] = num_island;
            insert_if_border({i, j});
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = current.first + dx[dir];
                    int Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= N || Y >= N)
                        continue;
                    if (!visited[X][Y] && Map[X][Y]) {
                        visited[X][Y] = true;
                        Map[X][Y] = num_island;
                        Q.push({X, Y});
                        insert_if_border({X, Y});
                    }
                }
            }
        }
    for (int i = 1; i <= num_island; i++)
        result = min(result, get_distance(i));
    cout << result;
}