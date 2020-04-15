#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) { return a.first < b.first; }
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, x, y; cin >> N; pair<int, int> slot[N] = {};
    for (int i = 0; i < N; i++) {
        cin >> x >> y; slot[i] = {x, y};
    }
    sort(slot, slot + N, compare);
    int t = 0, result = 0;
    for (int i = 0; i < N; i++) {
        if (slot[i].first < t) { continue; }
        else { result++; t = slot[i].second; }
    }
    cout << result;
}