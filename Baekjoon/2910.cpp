#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    int N, C; cin >> N >> C;
    int temp;
    unordered_map<int, int> occ_pos;
    unordered_map<int, int> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (!occ_pos.count(temp))
            occ_pos[temp] = i;
        M[temp]++;
    }
    vector<pair<int, pair<int, int> > > input;
    for (auto it : M)
        input.push_back({-it.second, {occ_pos[it.first], it.first}});
    sort(input.begin(), input.end());
    for (auto it : input)
        for (int i = 0; i < -it.first; i++)
            cout << it.second.second << ' ';
}