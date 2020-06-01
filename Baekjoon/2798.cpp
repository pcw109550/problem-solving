#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M; int value[N] = {};
    int result = 0;
    for (int i = 0; i < N; i++) { cin >> value[i]; }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int temp = value[i] + value[j] + value[k];
                if (M == temp) { cout << M; return 0; }
                if (M >  temp) {
                    if (result < temp) { result = temp; }
                }
            }
        }
    }
    cout << result;
}