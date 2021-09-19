#include <bits/stdc++.h>
using namespace std;

int n, p[100002][21], h[100002];
vector<int> adj[100002];
unordered_map<int, unordered_map<int, int> > len;
int cache[100002];
bool visited[100002];
int fuel[100002];

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
    queue<int> Q; Q.push(1);
    visited[1] = true; cache[1] = 0;
    p[1][0] = 1;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (auto next : adj[cur])
            if (!visited[next]) {
                p[next][0] = cur;
                h[next] = h[cur] + 1;
                visited[next] = true;
                cache[next] = cache[cur] + len[next][cur];
                Q.push(next);
            }
    }
}

int dist(int a, int root) {
    return cache[a] - cache[root];
}

int eval(int a) {
    int cur_fuel = fuel[a];
    for (int i = 20; i >= 0; i--) {
        int r = p[a][i];
        int d = dist(a, r);
        if (cur_fuel >= d) {
            cur_fuel -= d;
            a = r;
        }
    }
    return a;
}

int main(void) {
    // O(N * log(N))
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> fuel[i];
    int a, b, d;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b >> d;
        adj[a].push_back(b);
        adj[b].push_back(a);
        len[a][b] = len[b][a] = d;
    }
    bfs();
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= n; j++)
            p[j][i] = p[p[j][i - 1]][i - 1];
    for (int i = 1; i <= n; i++)
        cout << eval(i) << '\n';
}