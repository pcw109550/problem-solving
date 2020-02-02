#include <bits/stdc++.h>
using namespace std;
enum polar {N, S}; enum dir {COUNTERCLWS = -1, CLWS = 1};
enum polar gearstate[4][8];

void initGear() {
    string s; char *state;
    for (int i = 0; i < 4; i++) {
        getline(cin, s); state = (char *)s.c_str();
        for (int j = 0; j < 8; j++) { gearstate[i][j] = *(state + j) == '0' ? N : S; }
    }
}

void rotateGear(int idx, dir Dir) {
    if (Dir == CLWS) {
        enum polar end = gearstate[idx][7];
        for (int i = 6; i >= 0; i--) { gearstate[idx][i + 1] = gearstate[idx][i]; }
        gearstate[idx][0] = end;
    }
    if (Dir == COUNTERCLWS) {
        enum polar start = gearstate[idx][0];
        for (int i = 0; i < 7; i++)  { gearstate[idx][i] = gearstate[idx][i + 1]; }
        gearstate[idx][7] = start;
    }
}

void printState() {
    cout << '\n';
    for (int i = 0 ; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cout << gearstate[i][j];
        }
        cout << '\n';
    }
}

void updateGear() {
    int idx, Dir; cin >> idx >> Dir; idx -= 1;
    enum dir direction[4] = {}; direction[idx] = (dir) Dir;
    for (int i = idx; i < 3; i++) {
        if (gearstate[i][2] != gearstate[i + 1][6]) { direction[i + 1] = (dir)-direction[i]; }
    }
    for (int i = idx; i > 0; i--) {
        if (gearstate[i][6] != gearstate[i - 1][2]) { direction[i - 1] = (dir)-direction[i]; }
    }  
    for (int i = 0; i < 4; i++) { rotateGear(i, direction[i]); }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    initGear();
    int T, score = 0; cin >> T;
    for (int t = 0; t < T; t++) { updateGear(); }
    for (int i = 0; i < 4; i++) { score += gearstate[i][0] == N ? 0 : (1 << i); }
    cout << score;
}