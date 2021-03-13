#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    int N, temp; cin >> N;
    vector<int> pos, neg;
    for (int i = 0; i < N; i++) {
        cin >> temp; // temp never zero
        if (temp > 0)
            pos.emplace_back(temp);
        else
            neg.emplace_back(temp);
    }
    if (pos.size() == 0) {
        cout << neg[neg.size() - 2] + neg[neg.size() - 1];
        return 0;
    } else if (neg.size() == 0) {
        cout << pos[0] + pos[1];
        return 0;
    }
    int sum = INT_MAX;
    int result = 0;
    for (auto it : pos) {
        auto c = --lower_bound(neg.begin(), neg.end(), -it);
        for (int i = 0; i < 2 && c != neg.end(); i++) {
            if (sum > abs(*c + it)) {
                sum = abs(*c + it);
                result = *c + it;
            }
            c++;
        }
    }
    if (neg.size() >= 2)
        if (sum > abs(neg[neg.size() - 2] + neg[neg.size() - 1])) {
            sum = abs(neg[neg.size() - 2] + neg[neg.size() - 1]);
            result = neg[neg.size() - 2] + neg[neg.size() - 1];
        }
    if (pos.size() >= 2)
        if (sum > abs(pos[0] + pos[1])) {
            sum = abs(pos[0] + pos[1]);
            result = pos[0] + pos[1];
        }
    cout << result;
    return 0;
}
