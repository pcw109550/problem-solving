#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, temp; cin >> N >> M; int input[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp; cout << input[i][j] + temp;
            if (j != M) { cout << ' '; }
        }
        cout << '\n';
    }   
}