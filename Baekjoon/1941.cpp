#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    bool Map[5][5] = {}; char temp; int decision = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> temp; Map[i][j] = temp == 'S';
            if (Map[i][j]) { decision++; }
        }
    }
    if (decision < 4) { cout << 0; return 0; }
    vector<bool> ind;
    for (int i = 0; i < 18; i++)  { ind.push_back(0); }
    for (int i = 0; i < 7; i++) { ind.push_back(1); }
    int cnt = 0;
    do {
        bool group[5][5] = {}; int num = 0, start;
        for (int i = 0; i < 25; i++) {
            if (ind[i]) {
                group[i / 5][i % 5] = true; start = i;
                if (Map[i / 5][i % 5]) { num++; }
            }
        }
        if (num >= 4) {
            queue<pair<int, int>> Q; int num2 = 0;
            bool visited[5][5] = {}; visited[start / 5][start % 5] = true;
            Q.push({start / 5, start % 5});
            while (!Q.empty()) {
                num2++; auto current = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = current.first + dx[dir], Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= 5 || Y >= 5) { continue; }
                    if (!visited[X][Y] && group[X][Y]) {
                        visited[X][Y] = true; Q.push({X, Y});
                    }
                }
            }
            if (num2 == 7) { cnt++; }
        }
    } while (next_permutation(ind.begin(), ind.end()));
    cout << cnt;
}