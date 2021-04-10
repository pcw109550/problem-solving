#include <bits/stdc++.h>
using namespace std;
#define RING 1000000

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<vector<vector<int> > > D(N, vector<vector<int> >(2, vector<int> (3, 0)));
    D[0][0][0] = D[0][0][1] = D[0][1][0] = 1;
    for (int i = 1; i < N; i++) {
        D[i][0][0] = D[i - 1][0][0] + D[i - 1][0][1] + D[i - 1][0][2];
        D[i][0][0] %= RING;
        D[i][0][1] = D[i - 1][0][0];
        D[i][0][2] = D[i - 1][0][1];
        D[i][1][0] = D[i - 1][0][0] + D[i - 1][0][1] + D[i - 1][0][2] +
                     D[i - 1][1][0] + D[i - 1][1][1] + D[i - 1][1][2];
        D[i][1][0] %= RING;
        D[i][1][1] = D[i - 1][1][0];
        D[i][1][2] = D[i - 1][1][1];
    }
    int result = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            result += D[N - 1][i][j];
    result %= RING;
    cout << result;
}