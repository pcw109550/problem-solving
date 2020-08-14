#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, start, end, weight, next_weight, v1, Max = -1;
    cin >> N;
    vector<pair<int, int> > edge [N + 1] = {}; // {end, weight}
    for (int i = 0; i < N; i++) {
        cin >> start;
        while (true) {
            cin >> end;
            if (end == -1)
                break;
            cin >> weight;
            edge[start].push_back({end, weight});
        }
    }
    bool visited1[N + 1] = {};
    queue<pair<int, int> > Q; // {vertex, weight}
    visited1[1] = true;
    Q.push({1, 0});
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        start = current.first;
        weight = current.second;
        for (auto it : edge[start]) {
            end = it.first;
            next_weight = it.second;
            if (!visited1[end]) {
                visited1[end] = true;
                if (Max < weight + next_weight) {
                    Max = weight + next_weight;
                    v1 = end;
                }
                Q.push({end, weight + next_weight});
            }
        }
    }
    bool visited2[N + 1] = {};
    Q.push({v1, 0});
    visited2[v1] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        start = current.first;
        weight = current.second;
        for (auto it : edge[start]) {
            end = it.first;
            next_weight = it.second;
            if (!visited2[end]) {
                visited2[end] = true;
                Max = max(Max, weight + next_weight);
                Q.push({end, weight + next_weight});
            }
        }
    }
    cout << Max;
}   