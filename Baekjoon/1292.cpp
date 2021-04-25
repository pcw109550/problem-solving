#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int A, B; cin >> A >> B;
    int cnt = 0, x = 1, result = 0;
    for (int i = 1; i <= B; i++) {
        if (A <= i && i <= B)
            result += x;
        cnt++;
        if (x == cnt) {
            x++;
            cnt = 0;
        }
    }
    cout << result;
}