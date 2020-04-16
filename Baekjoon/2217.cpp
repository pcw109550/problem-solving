#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, Max = -1; cin >> N; short input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    sort(input, input + N, greater<int>());
    // Or we can just use counting sort
    for (int i = 0; i < N; i++) {
        if (Max < (i + 1) * input[i]) { Max = (i + 1) * input[i]; }
    }
    cout << Max;
}