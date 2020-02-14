#include <bits/stdc++.h>
using namespace std;
#define WALL 6
enum dir {W, A, S, D};
list<pair<int, pair<int, int>>> CCTV; int CCTVcnt;
int input[8][8];
int N, M;

void expose(pair<int, int> pos, dir Dir, bool *Map) {
    int posY = pos.first, posX = pos.second;
    switch (Dir) {
        case W: {
            for (int y = posY; y >= 0; y--) {
                *(Map + y * M + posX) = true; 
                if (input[y][posX] == WALL) { break; }
            }
            break;
        }
        case A: {
            for (int x = posX; x >= 0; x--) {
                *(Map + posY * M + x) = true;
                if (input[posY][x] == WALL) { break; }
            }
            break;
        }
        case S: {
            for (int y = posY; y < N; y++) {
                *(Map + y * M + posX) = true;
                if (input[y][posX] == WALL) { break; }
            }
            break;
        }
        case D: {
            for (int x = posX; x < M; x++) {
                *(Map + posY * M + x) = true;
                if (input[posY][x] == WALL) { break; }
            }
            break;
        }
        default:
            assert(0);
            break;
    }
}

int count(bool *Map) {
    int result = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (*(Map + y * M + x) == false && input[y][x] == 0) { result++; }
        }
    }
    return result;
}

void debug(bool *Map) {
    cout << '\n';
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << *(Map + y * M + x) << " ";
        }
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
            if (1 <= input[i][j] && input[i][j] <= 5) {
                CCTV.push_back({input[i][j], {i, j}}); CCTVcnt++;
            }
        }
    }
    int min = N * M;
    for (int i = 0; i < pow(4, CCTVcnt); i++) {
        bool Map[N][M] = {}; int idx = i; auto start = CCTV.begin();
        for (int j = 0; j < CCTVcnt; j++) { // bit encoding for bruteforce
            dir Dir = (dir) (idx & 0b11); idx >>= 2;
            auto cctv = *(start++); int type = cctv.first; auto pos = cctv.second;
            expose(pos, Dir, (bool *)Map);
            if (type >= 2 && type != 3) { expose(pos, (dir) (((int)Dir + 2) % 4), (bool *)Map); }
            if (type >= 3) { expose(pos, (dir) (((int)Dir + 1) % 4), (bool *)Map); }
            if (type >= 5) { expose(pos, (dir) (((int)Dir + 3) % 4), (bool *)Map); }
        }
        int result = count((bool *)Map);
        if (min > result) { min = result; } 
        // debug((bool *)Map);
        // cout << result << '\n';  
    }
    cout << min;
}