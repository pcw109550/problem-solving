#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int input[20]; int N, S, temp; cin >> N >> S;
    for (int i = 0; i < N; i++) { cin >> temp; input[i] = temp; }
    int result = 0; int sum = 0;
    for (int i = 1; i < (1 << N); i++) {
        temp = i;
        for (int j = 0; j < N; j++) {
            if (temp & 1) { sum += input[j]; } temp >>= 1;
        }
        if (sum == S) { result++; }
        sum = 0;
    }
    cout << result;
}