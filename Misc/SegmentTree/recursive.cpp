#include <bits/stdc++.h>
using namespace std;

long long init(vector<long long> &input, vector<long long> &tree, int node, int start, int end) {
    // O(N)
    if (start == end)
        tree[node] = input[start];
    else {
        int mid = (start + end) / 2;
        tree[node] = init(input, tree, node * 2, start, mid);
        tree[node] += init(input, tree, node * 2 + 1, mid + 1, end);
    }
    return tree[node];
}

void update(vector<long long> &tree, int node, int start, int end, int idx, long long diff) {
    // O(log (N))
    if (idx < start || idx > end)
        return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, idx, diff);
        update(tree, node * 2 + 1, mid + 1, end, idx, diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    // O(log (N))
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    long long result = sum(tree, node * 2, start, mid, left, right);
    result += sum(tree, node * 2 + 1, mid + 1, end, left, right);
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K;
    long long a, b, c, diff;
    cin >> N >> M >> K;
    vector<long long> input(N);
    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<long long> tree(tree_size);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    init(input, tree, 1, 0, N - 1);
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            diff = c - input[b - 1];
            input[b - 1] = c;
            update(tree, 1, 0, N - 1, b - 1, diff);
        } else
            cout << sum(tree, 1, 0, N - 1, b - 1, c - 1) << '\n';
    }
}