#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M; set<string> S; string s;
    priority_queue<string, vector<string>, greater<string>> PQ;
    for (int i = 0; i < N; i++) { // O(N * log(N))
        cin >> s; S.insert(s);
    }
    for (int i = 0; i < M; i++) { // O(M * log(N))
        cin >> s; auto it = S.find(s);
        if (it != S.end()) { PQ.push(s); }
    }
    cout << PQ.size() << '\n';
    while (!PQ.empty()) { // O(n)
        cout << PQ.top() << '\n'; PQ.pop();
    }
}