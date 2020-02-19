#include <bits/stdc++.h>
using namespace std;
char input[12][6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void debug(void) {
    cout << '\n';
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cout << input[i][j] << " ";
        }
        cout << '\n';
    }
}

void gravity(void) {
    int floor; char color;
    for (int i = 10 ; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            if (input[i][j] != '.' && input[i + 1][j] == '.') {
                floor = 11;
                color = input[i][j]; input[i][j] = '.';
                for (int k = i + 1; k < 12; k++) {
                    if (input[k][j] != '.') { floor = k - 1; break; }
                }
                input[floor][j] = color;
                // debug();
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> input[i][j];
        }
    }
    int trial = 0, size; char color; bool updated;
    do {
        bool visited[12][6] = {}; updated = false;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (!visited[i][j] && input[i][j] != '.') { color = input[i][j];
                    queue<pair<int, int>> Q; Q.push({i, j}); visited[i][j] = true;
                    list<pair<int, int>> E; size = 1; E.push_back({i, j});
                    while (!Q.empty()) {
                        auto current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir], Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= 12 || Y >= 6) { continue; }
                            if (!visited[X][Y] && input[X][Y] == color) {
                                visited[X][Y] = true; size++; Q.push({X, Y}); E.push_back({X, Y});
                            }
                        }
                    }
                    if (size >= 4) {
                        updated = true;
                        for (auto it = E.begin(); it != E.end(); it++) {
                            auto current = *it;
                            input[current.first][current.second] = '.';
                        }
                    }
                }    
                visited[i][j] = true; 
            }
        }
        gravity();
        if (updated) { trial++; }
    } while (updated);
    cout << trial;
}