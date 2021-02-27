#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N log(N))
    int N, x, temp;
    unordered_map<int, vector<int> > S;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        S[temp].push_back(i);
    }
    cin >> x;
    int result = 0;
    for (auto it : S) {
        int t1 = it.first, t2 = x - t1;
        if (!S.count(t2))
            continue;
        auto start = S[t2].begin();
        for (auto num : S[t1]) {
            auto temp = upper_bound(start, S[t2].end(), num);
            result += S[t2].end() - temp;
            start = temp;
        }
    }
    cout << result;
}