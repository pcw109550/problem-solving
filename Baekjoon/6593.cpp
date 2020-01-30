#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, -1, 0,  0, 0,  0};
int dy[6] = {0,  0, 1, -1, 0,  0};
int dz[6] = {0,  0, 0,  0, 1, -1};

void debug(int *input, int L, int R, int C) {
    printf("\n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                printf("%d ", *(input + i * R * C + j * C + k));
            }
            printf("\n");
        }
        printf("\n");
    }
}


int main(void) {
    int L, R, C; 
    while(scanf("%d %d %d", &L, &R, &C) != -1) {
        if (L == 0 && R == 0 && C == 0) {return 0;}
        int input[L][R][C] = {}; char temp[C + 1] = {};
        pair<int, pair<int, int>> start, end;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                scanf("%s", &temp);
                for (int k = 0; k < C; k++) {
                    if (temp[k] == 'S') { input[i][j][k] = 1; start = {i, {j, k}}; }
                    if (temp[k] == '.') { input[i][j][k] = 1; }
                    if (temp[k] == '#') { input[i][j][k] = 0; }
                    if (temp[k] == 'E') { input[i][j][k] = 1; end = {i, {j, k}}; }
                }
            }
        }
        queue<pair<int, pair<int, int>>> Q;
        Q.push({start.first, {start.second.first, start.second.second}});
        input[start.first][start.second.first][start.second.second] = 2;
        while (!Q.empty()) {
            pair<int, pair<int, int>> current = Q.front(); Q.pop();
            for (int dir = 0; dir < 6; dir++) {
                int X = current.first + dx[dir];
                int Y = current.second.first + dy[dir];
                int Z = current.second.second + dz[dir];
                if (X < 0 || Y < 0 || Z < 0 || X >= L || Y >= R || Z >= C) { continue; }
                if (input[X][Y][Z] == 0) { continue; }
                if (input[X][Y][Z] == 1) {
                    input[X][Y][Z] = input[current.first][current.second.first][current.second.second] + 1;
                    Q.push({X, {Y, Z}});
                }
                if (input[X][Y][Z] > 2 && input[X][Y][Z] > input[current.first][current.second.first][current.second.second] + 1) {
                    input[X][Y][Z] = input[current.first][current.second.first][current.second.second];
                    Q.push({X, {Y, Z}});
                }
            }
        }
        //debug((int *)input, L, R, C);
        int destX = end.first, destY = end.second.first, destZ = end.second.second;
        if (input[destX][destY][destZ] == 1) { cout << "Trapped!\n"; }
        else { cout << "Escaped in " << input[destX][destY][destZ] - 2 << " minute(s).\n"; }
        // Multiple exit :D not considered :C
    }
}