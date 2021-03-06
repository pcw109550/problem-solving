#include <bits/stdc++.h>
using namespace std;
int N, K;

void sub() {
    if (N == 2 && K > 1) {
        cout << "NO";
        return;
    } else if (K > (N - 1) * N) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    vector<vector<char> > temp (N, vector<char>(N, '#'));
    for (int i = 1; i < N - 1; i++)
        temp[i][i] = '.';
    temp[N - 1][0] = temp[0][N - 1] = '.';
    int num_del = N * (N - 1) - K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (num_del > 0 && temp[i][j] == '#') {
                num_del--;
                temp[i][j] = '.';
            }
            cout << temp[i][j];
        }
        cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    sub();
}