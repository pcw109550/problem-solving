#include <bits/stdc++.h>
using namespace std;
enum state { DIRTY, WALL, CLEAN };
enum dir { NORTH, EAST, SOUTH, WEST };
int N, M, x, y; dir currentDir;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int input[50][50];

inline dir nextdir(dir d) {
    if (d == NORTH) { return WEST;  }
    if (d == SOUTH) { return EAST;  }
    if (d == WEST ) { return SOUTH; }
    if (d == EAST ) { return NORTH; }
}

inline dir oppositedir(dir d) {
    if (d == NORTH) { return SOUTH;  }
    if (d == SOUTH) { return NORTH;  }
    if (d == WEST ) { return EAST; }
    if (d == EAST ) { return WEST; }
}

void debug() {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << input[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); int d;
    cin >> N >> M >> x >> y >> d; currentDir = (dir) d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
        }
    }
    int result = 0;
    while (true) {
begin:
        if (input[x][y] != CLEAN) { result++; } input[x][y] = CLEAN;    
        for (int i = 0; i < 4; i++) {
            dir nextDir = nextdir(currentDir);
            int X = x + dx[nextDir], Y = y + dy[nextDir];
            if (X < 0 || Y < 0 || X >= N || Y >= M) { currentDir = nextDir; continue; }
            if (input[X][Y] == DIRTY) { currentDir = nextDir; x = X; y = Y; goto begin; }
            else { currentDir = nextDir; continue; } 
        }
        int X = x + dx[oppositedir(currentDir)]; // X, Y checked
        int Y = y + dy[oppositedir(currentDir)];
        if (input[X][Y] == WALL ) { break; }
        x = X; y = Y;
    }
    cout << result;
}