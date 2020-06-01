#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, F; cin >> N >> F;
    N -= N % 100;
    int result = 0;
    for (int i = 0; i < 100; i++) {
        if (!((N + i) % F)) { result = i; break; }
    }
    if (result < 10) { cout << '0'; }
    cout << result;
}