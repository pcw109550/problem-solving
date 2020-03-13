#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, start, end, cnt = 0; cin >> N; int input[501] = {};
    for (int i = 0; i < N; i++) {
        cin >> start >> end; input[start] = end; cnt++;
    }
    int D[501] = {}, Max = -1; // LIS O(n ** 2)
    for (int i = 1; i < 501; i++) {
        if (input[i] != 0) { D[i] = 1; } else { continue; }
        for (int j = i - 1; j >= 1; j--) {
            if (input[i] > input[j]) {
                D[i] = max(D[i], D[j] + 1);
            }
        }
        Max = max(Max, D[i]);
    }
    cout << cnt - Max;  
}