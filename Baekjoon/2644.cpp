#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, target1, target2, T, x, y;
    cin >> N >> target1 >> target2 >> T;
    target1--; target2--;
    vector<int> Map[N] = {};
    for (int i = 0; i < T; i++) {
        cin >> x >> y; x--; y--;
        Map[x].push_back(y); Map[y].push_back(x);
    }
    pair<bool, int> visited[N] = {};
    queue<int> Q; Q.push(target1); visited[target1] = {true, 0};
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (int i = 0; i < Map[current].size(); i++) {
            int temp = Map[current][i];
            if (!visited[temp].first) {
                visited[temp] = {true, visited[current].second + 1};
                Q.push(temp);
            } else {
                if (visited[temp].second > visited[current].second + 1) {
                    visited[temp].second = visited[current].second + 1;
                    Q.push(temp);
                }
            }
        }
    }
    cout << (visited[target2].first ? visited[target2].second : -1);
}