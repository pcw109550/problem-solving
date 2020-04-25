#include <bits/stdc++.h>
using namespace std;
#define FIELD 1000000009

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; string s; bool isPrime = true; cin >> N >> s;
    if (N == 1) { isPrime = false; }
    else {
        for (int i = 2; i * i <= N; i++) {
            if (!(N % i)) { isPrime = false; break; }
        }
    }
    cout << (isPrime ? "Yes" : "No");
}