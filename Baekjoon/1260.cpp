#include <bits/stdc++.h>
using namespace std;
int N, M;
bool input[10000][10000] = {}; bool visited[10000] = {}, visited2[10000] = {};
list<int> DFS;

void doDFS(int start) {
    visited2[start] = true; DFS.push_back(start);
    for (int i = 0; i < N; i++) {
        if (input[start][i] && !visited2[i]) {
            doDFS(i);
        }
    }
}

int main(void) {
    int p, q, start; cin >> N >> M >> start; start--;
    for (int i = 0; i < M; i++) {
        cin >> p >> q; input[p - 1][q - 1] = true; input[q - 1][p - 1] = true;
    }

    // DFS
    doDFS(start);

    // BFS
    queue<int> Q; Q.push(start); visited[start] = true; list<int> BFS;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop(); BFS.push_back(current);
        for (int i = 0; i < N; i++) {
            if (input[current][i] && !visited[i]) {
                Q.push(i); visited[i] = true;
            }
        }
    }

    for (auto it = DFS.begin(); it != DFS.end(); it++) {
        cout << *it + 1 << " ";
    }
    cout << '\n';
    for (auto it = BFS.begin(); it != BFS.end(); it++) {
        cout << *it + 1 << " ";
    }
}