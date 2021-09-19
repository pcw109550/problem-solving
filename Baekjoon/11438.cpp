#include <bits/stdc++.h>
using namespace std;

int n, m, p[100002][21], h[100002];
vector<int> adj[100002];
bool visited[100002];

int f(int k, int x) {
    int idx = 0;
    while (k > 0) {
        if (k & 1)
            x = p[x][idx]; 
        k >>= 1;
        idx++;
    }
    return x;
}

void bfs(void) {
    h[1] = 1;
    queue<int> Q; Q.push(1); visited[1] = true;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (auto next : adj[cur])
            if (!visited[next]) {
                p[next][0] = cur;
                h[next] = h[cur] + 1;
                visited[next] = true;
                Q.push(next);
            }
    }
}

int lca(int a, int b) {
    if (h[a] < h[b])
        swap(a, b);
    a = f(h[a] - h[b], a);
    if (a == b)
        return a;
    for (int i = 20; i >= 0; i--)
        if (p[a][i] != p[b][i]) {
            a = p[a][i]; b = p[b][i];
        }
    return p[a][0];
}

int main(void) {
    // O(N * log(N) + M * log(N))
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    int a, b;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= n; j++)
            p[j][i] = p[p[j][i - 1]][i - 1];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}