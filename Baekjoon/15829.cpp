#include <bits/stdc++.h>
using namespace std;
#define FIELD 1234567891

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long acc = 1, result = 0;
    int N; string s; cin >> N >> s;
    for (int i = 0; i < N; i++) {
        result += (acc * (s[i] - 'a' + 1)) % FIELD;
        result %= FIELD;
        acc = acc * 31 % FIELD;
    }
    cout << result;
}