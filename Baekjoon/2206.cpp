#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void debug(int* input) {
    cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(input + m * i + j) << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); int N, M;
    cin >> N >> M; string s; char *c; getline(cin, s); n = N; m = M; int input[N][M] = {};
    queue<pair<int, int>> wall;
    for (int i = 0; i < N; i++) {
        getline(cin, s); c = (char *)s.c_str();
        for (int j = 0; j < M; j++) { input[i][j] = s[j] == '1'; }
    }
    // FAILED
}