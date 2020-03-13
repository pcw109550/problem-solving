#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int start, cnt, num, amount, temp; cin >> start;
        temp = start; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> num >> amount; temp += num * amount; 
        }
        cout << temp << '\n';
    }
}