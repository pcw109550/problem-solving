#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, temp, result = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (i == 0) { result = temp; }
        else { result = result - 1 + temp; }
    }
    cout << result;
}