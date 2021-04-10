#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unordered_set<string> S;
    string s;
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        S.insert(s);
    }
    int result = 0;
    for (int i = 0; i < M; i++) {
        cin >> s;
        if (S.count(s))
            result++;
    }
    cout << result;
}