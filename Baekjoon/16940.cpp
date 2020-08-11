#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, x, y;
    cin >> N;
    unordered_set<int> edge[N + 1] = {};
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        edge[x].insert(y);
        edge[y].insert(x);
    }
    vector<int> trace;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (i == 0 && x != 1) {
            cout << 0;
            return 0;
        }
        trace.emplace_back(x);
    }
    auto probe = trace.begin();
    vector<int> group, temp;
    group.emplace_back(1); // always start at 1
    while (probe != trace.end()) {
        for (auto current : group) {
            for (int i = 0; i < edge[current].size(); i++) {
                probe++;
                if (probe == trace.end()) {
                    cout << 1;
                    return 0;
                }
                if (edge[current].find(*probe) != edge[current].end()) {
                    temp.emplace_back(*probe);
                } else {
                    probe--;
                }
            }
        }
        if (temp.empty()) {
            cout << 0;
            return 0;
        }
        group.clear();
        group = temp;
        temp.clear();
    }
}   