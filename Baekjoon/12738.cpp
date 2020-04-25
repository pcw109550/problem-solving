#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; vector<int> D;
    for (int i = 0; i < N; i++) { // LIS
        int temp; cin >> temp;    // O(N * log(N))
        auto it = lower_bound(D.begin(), D.end(), temp);
        if (it == D.end()) {
            D.push_back(temp);
        } else {
            *it = temp;
        }
    }
    cout << D.size();
}