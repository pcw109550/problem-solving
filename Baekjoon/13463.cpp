#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, P, X, L;
    cin >> N >> P >> X >> L;
    int time[N + 1] = {};
    fill(time, time + N + 1, -1);
    vector<int> edge[N + 1] = {};
    int weight[N + 1] = {};
    int num_exit[N + 1] = {};
    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
        weight[x]++;
        weight[y]++;
    }
    bool visited[N + 1] = {};
    vector<int> exited;
    time[L] = 0;
    exited.push_back(L);
    int cnt = 1;
    while (exited.size() > 0) {
        vector<int> next;
        for (auto it : exited) {
            visited[it] = true;
            for (auto neigh : edge[it]) {
                if (visited[neigh])
                    continue;
                num_exit[neigh]++;
                if (num_exit[neigh] * 2 >= weight[neigh]) {
                    if (time[neigh] == -1) {
                        next.push_back(neigh);
                        time[neigh] = cnt;
                    }
                }
            }
        }
        exited = next;
        cnt++;
    }
    cout << (time[X] == -1 ? "stay" : "leave");
}   