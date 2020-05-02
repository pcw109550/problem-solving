#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int D[3]; string s;
    cin >> D[0] >> D[1] >> D[2] >> s;
    sort(D, D + 3);
    cout << D[s[0] - 'A'] << ' ' << D[s[1] - 'A'] << ' ' << D[s[2] - 'A']; 
}