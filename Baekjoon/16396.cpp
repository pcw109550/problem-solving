#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, x, y, temp; cin >> N; bool Map[10000] = {};
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (x > y) { temp = x; x = y; y = temp; }
        for (int j = x; j < y; j++) {
            if (!Map[j]) { Map[j] = true; }        
        }
    }
    int result = 0;
    for (int i = 1; i <= 9999; i++) {
        if (Map[i]) { result++; }
    } // O(n ** 2)
    cout << result;
}