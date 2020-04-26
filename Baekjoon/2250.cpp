#include <bits/stdc++.h>
using namespace std;
int depth[10001] = {},  leftnum[10001] = {}, rightnum[10001] = {};
int parent[10001] = {}, leftnode[10001] = {}, rightnode[10001] = {};
int coord[10001] = {};

void postorder(int cur) {
    if (leftnode[cur] != -1)  {
        postorder(leftnode[cur]);
        leftnum[cur] = leftnum[leftnode[cur]] + rightnum[leftnode[cur]] + 1;
    }
    if (rightnode[cur] != -1) {
        postorder(rightnode[cur]);
        rightnum[cur] = leftnum[rightnode[cur]] + rightnum[rightnode[cur]] + 1;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, idx; cin >> N; int root = N * (N + 1) / 2, maxdepth = 0;
    for (int i = 1; i <= N; i++) {
        cin >> idx;
        cin >> leftnode[idx] >> rightnode[idx];
        if (leftnode[idx]  != -1) { root -= leftnode[idx]; }
        if (rightnode[idx] != -1) { root -= rightnode[idx];}
    }
    postorder(root);      // find relative coord O(N)
    stack<int> S; S.push(root);
    coord[root] = leftnum[root] + 1;
    while (!S.empty()) {  // DFS: find absolute coord and depth O(N)
        int current = S.top(); S.pop();
        if (leftnode[current] != -1) {
            S.push(leftnode[current]);
            coord[leftnode[current]] = coord[current] - rightnum[leftnode[current]] - 1;
            depth[leftnode[current]] = depth[current] + 1;
            maxdepth = max(maxdepth, depth[leftnode[current]]);
        }
        if (rightnode[current] != -1) {
            S.push(rightnode[current]);
            coord[rightnode[current]] = coord[current] + leftnum[rightnode[current]] + 1;
            depth[rightnode[current]] = depth[current] + 1;
            maxdepth = max(maxdepth, depth[rightnode[current]]);
        }
    }
    vector<int> width[maxdepth + 1];
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        width[depth[i]].push_back(coord[i]);
    }
    for (int i = 0; i <= maxdepth; i++) {
        result.push_back(*max_element(width[i].begin(), width[i].end()) - \
                         *min_element(width[i].begin(), width[i].end()) + 1);
    }
    auto it = max_element(result.begin(), result.end());
    cout << (it - result.begin()) + 1 << ' ' << *it;
}