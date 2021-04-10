#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    string s; int Max = 0;
    unordered_map<string, int> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        M[s]++;
        if (Max <= M[s]) {
            Max = M[s];
        }
    }
    vector<string> temp;
    for (auto it: M)
        if (it.second == Max)
            temp.push_back(it.first);
    sort(temp.begin(), temp.end());
    cout << temp[0];
}