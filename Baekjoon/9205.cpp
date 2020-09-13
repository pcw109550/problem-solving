#include<bits/stdc++.h>
using namespace std;

inline int distance(pair<int, int> T1, pair<int, int> T2) {
    return abs(T1.first - T2.first) + abs(T1.second - T2.second);
}

inline void task(void) {
    int N, cur_dist;
    cin >> N;
    pair<int, int> start, end;
    pair<int, int> convs[N] = {};
    vector<bool> visited(N, false);
    cin >> start.first >> start.second;
    for (int i = 0; i < N; i++)
        cin >> convs[i].first >> convs[i].second;
    cin >> end.first >> end.second;
    if (distance(start, end) <= 1000) {
        cout << "happy\n";
        return;
    }
    auto current = start;
    queue<pair<int, int> > Q;
    Q.push(start);
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int i = 0; i < N; i++) {
            if (visited[i])
                continue;
            if (distance(current, convs[i]) > 1000)
                continue;
            visited[i] = true;
            Q.push(convs[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] && distance(end, convs[i]) <= 1000) {
            cout << "happy\n";
            return;
        }
    }
    cout << "sad\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        task();
}   