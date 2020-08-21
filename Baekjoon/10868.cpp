#include <bits/stdc++.h>
using namespace std;

int init(vector<int> &input, vector<int > &tree, int node, int start, int end) {
    // O(N)
    if (start == end)
        tree[node] = input[start];
    else {
        int mid = (start + end) / 2;
        int l = init(input, tree, node * 2, start, mid);
        int r = init(input, tree, node * 2 + 1, mid + 1, end);
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
    int N, K, a, b;
    cin >> N >> K;
    vector<int> input(N);
    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<int> tree(tree_size);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    init(input, tree, 1, 0, N - 1);
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        int result = find(tree, 1, 0, N - 1, a - 1, b - 1);
        cout << result << '\n';
    }
}