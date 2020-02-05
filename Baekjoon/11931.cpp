#include <bits/stdc++.h>
using namespace std;
int input[1000000];

void mergesort(int a, int b) {
    if (a == b) { return; }
    int half = a + (b - a) / 2;
    mergesort(a, half); mergesort(half + 1, b);
    int local[b - a + 1] = {};
    int idx1 = a, idx2 = half + 1, idx = 0;
    while (idx1 <= half && idx2 <= b) {
        if (input[idx1] > input[idx2]) { local[idx++] = input[idx2++]; }
        else { local[idx++] = input[idx1++]; }
    }
    while (idx1 <= half) {
        local[idx++] = input[idx1++];
    }
    while (idx2 <= b) {
        local[idx++] = input[idx2++];
    }
    for (int i = a; i <= b; i++) {
        input[i] = local[i - a];
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    mergesort(0, N - 1);
    for (int i = N - 1; i >= 0; i--) { cout << input[i] << '\n'; }
}