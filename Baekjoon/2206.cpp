#include <bits/stdc++.h>
using namespace std;
int n, m;
int input[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void debug(int *state) {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(state + m * i + j) << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); int N, M;
    cin >> N >> M; string s; char *c; getline(cin, s); n = N; m = M;
    queue<pair<int, int>> wall;
    for (int i = 0; i < N; i++) {
        getline(cin, s); c = (char *)s.c_str();
        for (int j = 0; j < M; j++) { input[i][j] = s[j] == '1'; }
    }

    bool visited1[N][M] = {}; set<pair<int, int>> wall1;
    int length[N][M] = {}; length[0][0] = 1;
    queue<pair<int, int>> Q; Q.push({0, 0}); visited1[0][0] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir], Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
            if (input[X][Y] == 1) { wall1.insert({X, Y}); continue; }
            if (!visited1[X][Y]) {
                visited1[X][Y] = true; length[X][Y] = length[current.first][current.second] + 1;
                Q.push({X, Y}); continue;
            }
            if (length[X][Y] > length[current.first][current.second] + 1) {
                length[X][Y] = length[current.first][current.second] + 1;
                Q.push({X, Y}); continue;
            }
        }
    }
    int result = -1;
    if (length[N - 1][M - 1] > 0) {
        result = length[N - 1][M - 1];
    }

    bool visited2[N][M] = {}; set<pair<int, int>> wall2;
    Q.push({N - 1, M - 1}); visited2[N - 1][M - 1] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir], Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
            if (input[X][Y] == 1) { wall2.insert({X, Y}); continue; }
            if (!visited2[X][Y]) {
                visited2[X][Y] = true; Q.push({X, Y});
            }
        }
    }

    set<pair<int, int>> intersect;

    set_intersection(wall1.begin(), wall1.end(), wall2.begin(), wall2.end(), inserter(intersect, intersect.begin()));
    for (auto it = intersect.begin(); it != intersect.end(); it++) {
        auto here = *it;
        int length[N][M] = {}; bool visited[N][M] = {};
        Q.push({0, 0}); visited[0][0] = true; length[0][0] = 1;
        while (!Q.empty()) {
            auto current = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int X = current.first + dx[dir], Y = current.second + dy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                if (!(X == here.first && Y == here.second) && input[X][Y] == 1) { continue; }
                if (!visited[X][Y]) {
                    visited[X][Y] = true; length[X][Y] = length[current.first][current.second] + 1;
                    Q.push({X, Y}); continue;
                }
                if (length[X][Y] > length[current.first][current.second] + 1) {
                    length[X][Y] = length[current.first][current.second] + 1;
                    Q.push({X, Y}); continue;
                }
            }
        }
        //debug((int *)length);
        if (length[N - 1][M - 1] > 0) {
            if (result < length[N - 1][M - 1]) { result = length[N - 1][M - 1]; }
        }
    }
    cout << result;
    // GOT TIMEOUT :C
}