#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, vector<int> > &a, pair<string, vector<int> > &b) {
    auto s1 = a.second, s2 = b.second;
    if (s1[0] != s2[0])
        return s1[0] > s2[0];
    if (s1[1] != s2[1])
        return s1[1] < s2[1];
    if (s1[2] != s2[2])
        return s1[2] > s2[2];
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    int N; cin >> N;
    string temp; int a, b, c;
    vector<pair<string, vector<int> > > input;
    for (int i = 0; i < N; i++) {
        cin >> temp >> a >> b >> c;
        input.push_back({temp, vector<int> {a, b, c}});
    }
    sort(input.begin(), input.end(), compare);
    for (auto it : input)
        cout << it.first << '\n';
}