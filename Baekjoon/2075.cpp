#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int input[N * N] = {};
    for (int i = 0; i < N * N; i++) { cin >> input[i]; }
    sort(input, input + N * N); // O(n * log (n))
    cout << input[N * N - N];
    // Using priority queue: O(n * log (n))
}