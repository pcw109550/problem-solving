#include <bits/stdc++.h>
using namespace std;
int n;
bool isused[12]; int arr[6];

void backtrack(int k, int input[]) {
    if (k == 6) { for (int i = 0; i < 6; i++) { cout << input[arr[i]] << " "; } cout << '\n'; return; }
    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            if (k == 0 || arr[k - 1] < i) { isused[i] = true; arr[k] = i; backtrack(k + 1, input); isused[i] = false;}
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    bool start = true;
    while (true) {
        int N; cin >> N; if (N == 0) { return 0; } else { if (!start) { cout << '\n'; } else { start = false; } } n = N;
        int input[N] = {}; for (int i = 0; i < N; i++) { cin >> input[i]; }
        backtrack(0, input);
        for (int i = 0; i < 12; i++) { isused[i] = false; }
    }
}