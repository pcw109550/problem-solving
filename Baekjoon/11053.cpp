#include <bits/stdc++.h>
using namespace std;
int input[1001]; 
int D[1001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, result = 1; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> input[i];
    }
    for (int i = 1; i <= N; i++) {
        D[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
            if (input[i] > input[j]) {
                D[i] = max(max(1, D[j]) + 1, D[i]);
                if (result < D[i]) { result = D[i]; }
            }
        }
    }
    cout << result;
}