#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int Max = -1, sum = 0, temp, N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        Max = max(temp, Max);
        sum += temp;
    }
    double result = (double) sum * 100 / (Max * N);
    cout << setprecision(5) << result;
}