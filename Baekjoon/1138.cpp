#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int input[N] = {};
    int output[N] = {};
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < N; i++) {
        int start = input[i];
        for (int j = 0; j <= start; j++) {
            if (output[j] && output[j] < i + 1) {
                start++;
            }
        }
        output[start] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cout << output[i] << ' ';
    }
}