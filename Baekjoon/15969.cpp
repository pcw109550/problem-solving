#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, temp, Min = 1001, Max = -1; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        Min = min(Min, temp);
        Max = max(Max, temp);
    }
    cout << Max - Min;
}