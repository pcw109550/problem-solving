#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, num, temp, result; cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> num; result = 0;
        for (int j = 0; j < num; j++) { cin >> temp; result += temp; }
        cout << result << '\n';
    }
}