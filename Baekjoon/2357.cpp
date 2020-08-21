#include <bits/stdc++.h>
using namespace std;

pair<int, int> init(vector<int> &input, vector<pair<int, int> > &tree, int node, int start, int end) {
    // O(N)
    if (start == end)
        tree[node] = {input[start], input[end]};
    else {
        int mid = (start + end) / 2;
        auto l = init(input, tree, node * 2, start, mid);
        auto r = init(input, tree, node * 2 + 1, mid + 1, end);
        tree[node] = {min(l.first, r.first), max(l.second, r.second)};
    }
    return tree[node];
}

pair<int, int> find(vector<pair<int, int> > &tree, int node, int start, int end, int left, int right) {
    // O(log (N))
    if (left > end || right < start)
        return {1 << 30, -1};
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    auto l = find(tree, node * 2, start, mid, left, right);
    auto r = find(tree, node * 2 + 1, mid + 1, end, left, right);
    return {min(l.first, r.first), max(l.second, r.second)};
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K, a, b;
    cin >> N >> K;
    vector<int> input(N);
    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<pair<int, int> > tree(tree_size);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    init(input, tree, 1, 0, N - 1);
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        auto result = find(tree, 1, 0, N - 1, a - 1, b - 1);
        cout << result.first << ' ' << result.second << '\n';
    }
}