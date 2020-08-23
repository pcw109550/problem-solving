#include <bits/stdc++.h>
using namespace std;

inline pair<int,int> compare(pair<int, int> &l, pair<int, int> &r) {
    if (l.second == r.second) 
        return (l.first < r.first ? l : r);
    return (l.second < r.second ? l : r);
}

pair<int, int> init(vector<int> &input, vector<pair<int, int> > &tree, int node, int start, int end) {
    // O(N)
    if (start == end) {
        tree[node] = {start, input[start]}; // {idx, value}
    } else {
        int mid = (start + end) / 2;
        auto l = init(input, tree, node * 2, start, mid);
        auto r = init(input, tree, node * 2 + 1, mid + 1, end);
        tree[node] = compare(l, r);
    }
    return tree[node];
}

pair<int, int> update(vector<pair<int, int> > &tree, int node, int start, int end, int idx, int value) {
    // O(log (N))
    pair<int, int> l, r;
    int mid = (start + end) / 2;
    if (start >= end) {
        tree[node] = {idx, value};
    } else if (idx > mid) {
        l = tree[node * 2];
        r = update(tree, node * 2 + 1, mid + 1, end, idx, value);
        tree[node] = compare(l, r);
    } else if (idx <= mid) {
        l = update(tree, node * 2, start, mid, idx, value);
        r = tree[node * 2 + 1];
        tree[node] = compare(l, r);
    }
    return tree[node];
}

pair<int, int> query(vector<pair<int, int> > &tree, int node, int start, int end, int left, int right) {
    // O(log (N))
    if (left > end || right < start)
        return {-1, 1 << 30};
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    auto l = query(tree, node * 2, start, mid, left, right);
    auto r = query(tree, node * 2 + 1, mid + 1, end, left, right);
    pair<int, int> result = compare(l, r);
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    int a, b, c;
    cin >> N;
    vector<int> input(N);
    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<pair<int, int> > tree(tree_size); // {idx, value}
    for (int i = 0; i < N; i++)
        cin >> input[i];
    init(input, tree, 1, 0, N - 1);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            input[b] = c;
            update(tree, 1, 0, N - 1, b, c);
        } else {
            auto result = query(tree, 1, 0, N - 1, b - 1, c - 1);
            cout << result.first + 1 << '\n';
        }
    }
}