#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K; cin >> K; K--; int acc = 2, cnt = 0;
    vector<bool> bin;
    while (true) {
        cnt++;
        if (K >= acc) {
            K -= acc; acc <<= 1;
        } else { break; }
    }
    while (K > 0) {
        bin.push_back(K & 1);
        K >>= 1;
    }
    for (int i = 0; i < cnt - bin.size(); i++) {
        cout << 4;
    }
    for (auto it = bin.rbegin(); it != bin.rend(); it++) {
        cout << (*it ? 7 : 4);
    }
}