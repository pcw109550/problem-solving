#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int time[N + 1] = {};
    fill(time, time + N + 1, -1);
    vector<int> edge[N + 1] = {};
    int weight[N + 1] = {};
    int num_rumor[N + 1] = {};
    for (int i = 1; i <= N; i++) {
        int x;
        while (true) {
            cin >> x;
            if (x == 0)
                break;
            edge[i].push_back(x);
        }
        weight[i] = edge[i].size();
    }
    int M; cin >> M;
    bool visited[N + 1] = {};
    vector<int> rumored;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        time[x] = 0;
        rumored.push_back(x);
    }
    int cnt = 1;
    while (rumored.size() > 0) {
        vector<int> next;
        for (auto it : rumored) {
            visited[it] = true;
            for (auto neigh : edge[it]) {
                if (visited[neigh])
                    continue;
                num_rumor[neigh]++;
                if (num_rumor[neigh] * 2 >= weight[neigh]) {
                    if (time[neigh] == -1) {
                        next.push_back(neigh);
                        time[neigh] = cnt;
                    }
                }
            }
        }
        rumored = next;
        cnt++;
    }
    for (int i = 1; i <= N; i++)
        cout << time[i] << ' ';
}   