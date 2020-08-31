#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, x, y;
    cin >> N >> M;
    vector<int> edge[N + 1] = {};
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        edge[x].emplace_back(y);
        edge[y].emplace_back(x);        
    }
    int Min = 1 << 30, result = -1;
    queue<int> Q;
    for (int i = N; i >= 1; i--) {
        bool visited[N + 1] = {};
        int weight[N + 1] = {};
        int sum = 0;
        Q.push(i); visited[i] = true;
        while (!Q.empty()) {
            int current = Q.front(); Q.pop();
            for (auto it : edge[current]) {
                if (!visited[it]) {
                    visited[it] = true;
                    weight[it] = weight[current] + 1;
                    sum += weight[it];
                    Q.push(it);
                }
            } 
        }
        if (sum <= Min) {
            Min = sum;
            result = i;
        }
    } 
    cout << result;
}   