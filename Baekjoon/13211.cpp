#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, result = 0; cin >> N;
    unordered_set<string> u;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s; u.insert(s);
    }
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s;
        auto search = u.find(s);
        if (search != u.end()) {
            result++;
        }
    }
    cout << result;
}