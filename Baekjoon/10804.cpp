#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    list<int> L; for (int i = 1; i <= 20; i++) { L.push_back(i); }
    for (int t = 0; t < 10; t++) {
        int a, b; cin >> a >> b;
        auto it1 = L.begin(), it2 = L.begin(); advance(it1, a - 1); advance(it2, b);
        reverse(it1, it2);
    }
    for (auto it = L.begin(); it != L.end(); it++) { cout << *it << " "; }
}