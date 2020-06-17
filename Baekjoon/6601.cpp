#include <bits/stdc++.h>
using namespace std;
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

inline void task(string p1, string p2) {
    bool Map[8][8] = {};
    pair<int, int> start = make_pair(p1[0] - 'a', p1[1] - '1');
    pair<int, int> end   = make_pair(p2[0] - 'a', p2[1] - '1');
    queue<pair<int, int> > Q;
    bool visited[8][8] = {};
    int  distance[8][8] = {};
    visited[start.first][start.second] = true;
    distance[start.first][start.second] = 1;
    Q.push(start);
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int X = current.first + dx[dir];
            int Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= 8 || Y >= 8) {
                continue;
            }
            if (!visited[X][Y]) {
                visited[X][Y] = true;
                distance[X][Y] = distance[current.first][current.second] + 1;
                Q.push({X, Y});
            }
        }
    }
    int result = distance[end.first][end.second] - distance[start.first][start.second];
    cout << "To get from " << p1 << " to " << p2 << " takes " << result << " knight moves.\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string p1, p2;
    while (!cin.eof()) {
        cin >> p1 >> p2;
        if (cin.eof()) { break; }
        task(p1, p2);
    }
}