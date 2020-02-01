#include <bits/stdc++.h>
using namespace std;
enum dir {UP, DOWN, SOUTH, EAST, WEST, NORTH};
int Map[20][20]; int command[1000];
int N, M, x, y, K; int cube[6];
inline void swap(int dir1, int dir2) {
    int temp; temp = cube[UP]; cube[UP] = cube[dir1]; cube[dir1] = cube[DOWN]; cube[DOWN] = cube[dir2]; cube[dir2] = temp;
}

bool rotate(int cmd) {
    int temp;
    if (cmd == 1 && y + 1 < M  ) { swap(WEST, EAST); y++; return true; } // E
    if (cmd == 2 && y - 1 >= 0 ) { swap(EAST, WEST); y--; return true; } // W
    if (cmd == 3 && x - 1 >= 0 ) { swap(SOUTH, NORTH); x--; return true; } // N
    if (cmd == 4 && x + 1 < N  ) { swap(NORTH, SOUTH); x++; return true; } // S
    return false;
}

int main(void) {
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
        }    
    }
    for (int i = 0; i < K; i++) { cin >> command[i]; }    
    for (int i = 0; i < K; i++) {
        if (rotate(command[i])) {
            cout << cube[UP] << '\n';
            if (Map[x][y] == 0) { Map[x][y] = cube[DOWN]; }
            else { cube[DOWN] = Map[x][y]; Map[x][y] = 0; }
        }
    }
}