#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> hypertube[M] = {};
    vector<int> idx[N + 1] = {};
    for (int i = 0; i < M; i++) {
        int temp;
        for (int j = 0; j < K; j++) {
            cin >> temp;
            hypertube[i].push_back(temp);
            idx[temp].push_back(i);
        }
    }
    int start = 1, end = N;
    bool visited[N + 1] = {};
    int distance[N + 1] = {};
    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    distance[start] = 1;
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (int tube_idx : idx[current]) {
            bool exhausted = true;
            for (int neigh : hypertube[tube_idx]) {
                if (!visited[neigh]) {
                    exhausted = false;
                    visited[neigh] = true;
                    distance[neigh] = distance[current] + 1;
                    Q.push(neigh);
                }
            }
            if (exhausted) {
                hypertube[tube_idx].clear();
            }
        }
    }
    cout << (distance[end] == 0 ? -1 : distance[end]);
}   