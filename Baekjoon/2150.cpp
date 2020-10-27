#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

int SCC_num, cnt, V, E;
vector<vector<int> > SCC;
bool finished[MAX + 1];
int SCC_idx[MAX + 1], preorder[MAX + 1];
vector<int> neighbors[MAX + 1];
stack<int> S;

int DFS(int cur) {
    int result = preorder[cur] = ++cnt;
    S.push(cur);
    for (auto &neighbor : neighbors[cur]) {
        if (!preorder[neighbor])
            result = min(result, DFS(neighbor));
        else if (!finished[neighbor])
            result = min(result, preorder[neighbor]);
    }
    if (result == preorder[cur]) {
        vector<int> SCC_current;
        while (true) {
            auto top = S.top(); S.pop();
            SCC_current.emplace_back(top);
            finished[top] = true;
            SCC_idx[top] = SCC_num;
            if (top == cur)
                break;
        }
        sort(SCC_current.begin(), SCC_current.end());
        SCC.push_back(SCC_current);
        SCC_num++;
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // Tarjan: O(V + E)
    int x, y; cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> x >> y;
        neighbors[x].emplace_back(y);
    }
    for (int i = 1; i <= V; i++)
        if (!preorder[i])
            DFS(i);
    sort(SCC.begin(), SCC.end());
    std::cout << SCC_num << '\n';
    for (auto &scc : SCC) {
        for (auto &elem : scc)
            std::cout << elem << ' ';
        std::cout << "-1\n";
    }
}