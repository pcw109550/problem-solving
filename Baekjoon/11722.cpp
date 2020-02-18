#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, result = 0; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int D[N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (input[i] < input[j]) {
                D[i] = max(D[j], D[i]);    
            }
        }
        D[i]++;
        if (D[i] > result) { result = D[i]; }
    }
    cout << result;
}