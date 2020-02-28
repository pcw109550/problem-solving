#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int D1[N] = {}, D2[N] = {}, temp;
    for (int i = 0; i < N; i++) {
        temp = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (input[i] > input[j]) { temp = max(temp, D1[j]); }
        }
        D1[i] += temp + 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        temp = 0;
        for (int j = i + 1; j < N; j++) {
            if (input[i] > input[j]) { temp = max(temp, D2[j]); }
        }
        D2[i] += temp + 1;
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        result = max(result, D1[i] + D2[i]);
    } result--;
    cout << result;
}