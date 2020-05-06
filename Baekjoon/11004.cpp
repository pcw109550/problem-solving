#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    nth_element(input, input + K - 1, input + N); cout << input[K - 1];
}