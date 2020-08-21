#include<bits/stdc++.h>
using namespace std;

int init(vector<int> &input, vector<int> &tree, int node, int start, int end) {
    // O(N)
    if (start == end) {
        tree[node] = input[start];
    } else {
        int mid = (start + end) / 2;
        int l = init(input, tree, node * 2, start, mid);
        int r = init(input, tree, node * 2 + 1, mid + 1, end);
        tree[node] = min(l, r);
    }
    return tree[node];
}

int update(vector<int> &tree, int node, int start, int end, int idx, int diff) {
    // O(log (N))
    int mid = (start + end) / 2, l, r;
    if (start >= end) {
        tree[node] = diff;
    } else if (idx > mid) {
        l = tree[node * 2];
        r = update(tree, node * 2 + 1, mid + 1, end, idx, diff);
        tree[node] = min(l, r);
    } else if (idx <= mid) {
        l = update(tree, node * 2, start, mid, idx, diff);
        r = tree[node * 2 + 1];
        tree[node] = min(l, r);
    }
    return tree[node];
}

int find(vector<int> &tree, int node, int start, int end, int left, int right) {
    // O(log (N))
    if (left > end || right < start)
        return 1 << 30;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    int l = find(tree, node * 2, start, mid, left, right);
    int r = find(tree, node * 2 + 1, mid + 1, end, left, right);
    return min(l, r);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, a, b, c;
    cin >> N;
    vector<int> input(N);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<int> tree(tree_size);
    init(input, tree, 1, 0, N - 1);
    cin >> M;
    while (M--) {
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            input[b] = c;
            update(tree, 1, 0, N - 1, b, c);
        } else if (a == 2) {
            b--; c--;
            int result = find(tree, 1, 0, N - 1, b, c);
            cout << result << '\n';
        } else
            assert(false);
    }
}