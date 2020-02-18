#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, temp, gcd; cin >> T; int first; cin >> first;
    for (int i = 1; i < T; i++) {
        cin >> temp; gcd = __gcd(temp, first);
        cout << first / gcd << "/" << temp / gcd << '\n'; 
    }
}