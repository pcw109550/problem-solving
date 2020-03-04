#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, target; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    sort(input, input + N); cin >> M;
    for (int t = 0; t < M; t++) {
        int start = 0, end = N - 1, mid; cin >> target;
        while (start <= end) { // Binary Search
            mid = (start + end) / 2;
            if      (input[mid] < target) { start = mid + 1; }
            else if (input[mid] > target) { end = mid - 1; }
            else { cout << "1\n"; break; }
        }
        if (start > end) { cout << "0\n"; }
    }
}