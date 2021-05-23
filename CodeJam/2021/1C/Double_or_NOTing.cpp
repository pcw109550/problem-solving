#include <bits/stdc++.h>
using namespace std;

int neg(int x) {
    if (x == 1)
        return 0;
    else if (x == 0)
        return 1;
    int MASK = (1 << (32 - __builtin_clz(x))) - 1;
    return (~x) & MASK; 
}

void task(int idx) {
    int S, E;
    string temp;
    cin >> temp; S = stoi(temp, 0, 2);
    cin >> temp; E = stoi(temp, 0, 2);
    vector<bool> visited (1 << 20, false);
    vector<int> distance (1 << 20, INT_MAX);
    queue<pair<int, int> > Q;
    visited[S] = true; distance[S] = 0;
    Q.push({S, 0});
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        int c1 = current.first << 1;
        int c2 = neg(current.first);
        vector<int> cands {c1, c2};
        for (auto c : cands) {
            if (c < 1 << 20) {
                if (!visited[c]) {
                    visited[c] = true;
                    distance[c] = current.second + 1;
                    Q.push({c, distance[c]});
                } else if (distance[c] > current.second + 1) {
                    distance[c] = current.second + 1;
                    Q.push({c, distance[c]});
                }
            }
        }
    }
    if (visited[E])
        cout << "Case #" << idx << ": " << distance[E] << endl;
    else
        cout << "Case #" << idx << ": IMPOSSIBLE" << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
        task(t);
    return 0;
}