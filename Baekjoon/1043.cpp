#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    bool truth[N + 1] = {};
    vector<int> groups[M] = {};
    queue<int> Q;
    int cnt, temp;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> temp;
        truth[temp] = true;
        Q.push(temp);
    }
    for (int i = 0; i < M; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> temp;
            groups[i].push_back(temp);
        }
    }
    // O(N ** 2)
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (auto group : groups) {
            bool propagate = false;
            for (auto it : group) {
                if (truth[it]) {
                    propagate = true;
                    break;
                }
            }
            if (propagate) {
                for (auto it : group) {
                    if (!truth[it]) {
                        truth[it] = true;
                        Q.push(it);
                    }
                }
            }
        }
    }
    int result = 0;
    // O(N ** 2)
    for (int i = 0; i < M; i++) {
        auto group = groups[i];
        bool truth_known = false;
        for (auto it : group) {
            if (truth[it]) {
                truth_known = true;
                break;
            }
        }
        if (!truth_known)
            result++;
    }
    cout << result;
}