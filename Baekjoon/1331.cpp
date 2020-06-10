#include <bits/stdc++.h>
using namespace std;
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
bool visited[6][6];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string current; bool valid = true, found;
    int prevx, prevy, startx, starty;
    for (int i = 0; i < 36 && valid; i++) {
        cin >> current;
        int x = current[0] - 'A';
        int y = current[1] - '1';
        if (visited[x][y]) {
            valid = false;
        } else {
            visited[x][y] = true;
        }
        if (i > 0) {
            found = false;
            for (int dir = 0; dir < 8; dir++) {
                int X = prevx + dx[dir];
                int Y = prevy + dy[dir];
                if (X == x && Y == y) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                valid = false;
            }
        } else {
            startx = x; starty = y;
        }
        prevx = x; prevy = y;
    }
    if (valid) {
        found = false;
        for (int dir = 0; dir < 8; dir++) {
            int X = prevx + dx[dir];
            int Y = prevy + dy[dir];
            if (X == startx && Y == starty) {
                found = true;
                break;
            }
        }
        if (!found) {
            valid = false;
        }
    }
    cout << (valid ? "Valid\n" : "Invalid\n");
}