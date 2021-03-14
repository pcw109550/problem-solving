#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    int N; long long temp; cin >> N;
    unordered_map<long long, long long> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        M[temp]++;
    }
    vector<pair<long long, long long> > data;
    for (auto it : M)
        data.push_back({it.second, -it.first});
    sort(data.begin(), data.end());
    cout << -(*data.rbegin()).second;
}