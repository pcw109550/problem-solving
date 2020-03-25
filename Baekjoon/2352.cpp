#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Max = 0; cin >> N;
    vector<int> D; D.push_back(-1); int temp; // LIS O(N * log(N))
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        if (D.back() < temp) { D.push_back(temp); Max++; }
        else { *lower_bound(D.begin(), D.end(), temp) = temp; }
    }
    cout << Max;
}