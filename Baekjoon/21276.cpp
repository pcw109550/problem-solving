#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    string name, a, b;
    unordered_map<int, string> enc;
    unordered_map<string, int> dec;
    unordered_map<int, set<string> > S;
    vector<int> edge[N + 1] = {};
    vector<int> indegree (N + 1, 0);
    set<string> names;
    for (int i = 1; i <= N; i++) {
        cin >> name;
        names.insert(name);
        enc[i] = name;
        dec[name] = i;
    }
    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        int x = dec[a], y = dec[b];
        edge[y].push_back(x);
        indegree[x]++;
        S[y].insert(a);
    }
    set<string> ancestor;
    vector<int> height (N + 1, 0);
    queue<int> Q;
    for (int i = 1; i <= N; i++)
        if (!indegree[i]) {
            ancestor.insert(enc[i]);
            Q.push(i);
        }
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (auto it : edge[current]) {
            indegree[it]--;
            height[it] = max(height[it], height[current] + 1);
            if (!indegree[it])
                Q.push(it);
        }
    }
    cout << ancestor.size() << '\n';
    for (auto it: ancestor)
        cout << it << ' ';
    cout << '\n';
    for (auto n : names) {
        cout << n << ' ';
        vector<string> temp;
        for (auto it : S[dec[n]])
            if (height[dec[n]] + 1 == height[dec[it]])
                temp.push_back(it);
        cout << temp.size() << ' ';
        for (auto it : temp)
            cout << it << ' ';
        cout << endl;
    }
}