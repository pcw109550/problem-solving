#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int result = 0;
    int start = input[0], end = input[0];
    for (int i = 1; i < N; i++) {
        if (input[i] > end) {
            end = input[i];
        } else {
            result = max(result, end - start);
            start = end = input[i];
        }
    }
    result = max(result, end - start);
    cout << result;
}