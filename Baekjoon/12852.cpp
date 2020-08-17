#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int D[N + 1] = {};
    int path[N + 1] = {};
    bool visited[N + 1] = {};
    queue<pair<int, int> > Q; // {node, weight}
    Q.push({N, 0});
    visited[N] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        int node = current.first;
        int weight = current.second;
        pair<bool, int> acc[3] = {};
        acc[0] = {node % 3 == 0 && node / 3 >= 0, node / 3};
        acc[1] = {node % 2 == 0 && node / 2 >= 0, node / 2};
        acc[2] = {node - 1 >= 0, node - 1};
        for (int i = 0; i < 3; i++) {
            if (acc[i].first) {
                int next = acc[i].second;
                if (!visited[next]) {
                    visited[next] = true;
                    D[next] = weight + 1;
                    path[next] = node;
                    Q.push({next, weight + 1});
                } else if (D[next] > weight + 1) {
                    D[next] = weight + 1;
                    path[next] = node;
                    Q.push({next, weight + 1});
                }                
            }
        }
    }
    cout << D[1] << '\n' << N << ' ';
    vector<int> trace;
    int current = 1;
    while (current != N) {
        trace.push_back(current);
        current = path[current];
    }
    for (auto it = trace.rbegin(); it != trace.rend(); it++) {
        cout << *it << ' ';
    }
}   