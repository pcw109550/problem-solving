#include <bits/stdc++.h>
using namespace std;
#define MAX 262144
#define yMAX 64
int input[MAX];
int D[yMAX][MAX];

int main(void) {
    // O(N * log(N))
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int result = 0, N; cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    for (int i = 1; i < yMAX; i++) {
        for (int j = 0; j < N; j++) {
            if (input[j] == i) {
                D[i][j] = 1;
                result = i;
            } else {
                int k = D[i - 1][j];
                if (k == 0)
                    continue;
                int l = D[i - 1][j + k];
                if (l == 0)
                    continue;
                D[i][j] = k + l;
                result = i;
            }
        }
    }
    cout << result << '\n';
}