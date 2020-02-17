#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, veclen, sum, temp; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> veclen; int vec1[veclen] = {}, vec2[veclen] = {};
        sum = 0;
        for (int i = 0; i < veclen; i++) { cin >> vec1[i]; }
        for (int i = 0; i < veclen; i++) { cin >> temp; sum += vec1[i] != temp; }
        cout << sum << '\n';
    }
}