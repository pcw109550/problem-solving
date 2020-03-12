#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; string s; cin >> s;
    int probe = 0, result = 1;
    while (probe < N) {
        if (s[probe] == 'S') { probe++; }
        else { probe += 2; }
        result++;
    }
    cout << min(N, result);
}