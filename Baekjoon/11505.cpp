#include <bits/stdc++.h>
using namespace std;
#define FIELD 1000000007

int init(vector<int> &input, vector<int> &tree, int node, int start, int end) {
    // O(N)
    if (start == end)
        tree[node] = input[start];
    else {
        int mid = (start + end) / 2;
        long long l = init(input, tree, node * 2, start, mid);
        long long r = init(input, tree, node * 2 + 1, mid + 1, end);
        tree[node] = l * r % FIELD;
    }
    return tree[node];
}

int update(vector<int> &tree, int node, int left, int right, int idx, int diff) {
    // O(log (N))
    int mid = (left + right) / 2;
    long long l, r;
    if (left >= right) {
        tree[node] = diff;        
    } else if (idx > mid) {
        l = tree[node * 2];
        r = update(tree, node * 2 + 1, mid + 1, right, idx, diff);
        tree[node] = l * r % FIELD;
    } else if (idx <= mid) {
        l = update(tree, node * 2, left, mid, idx, diff);
        r = tree[node * 2 + 1];
        tree[node] = l * r % FIELD;
    }
    return tree[node];
}

int mul(vector<int> &tree, int node, int start, int end, int left, int right) {
    // O(log (N))
    if (left > end || right < start)
        return 1;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    long long l = mul(tree, node * 2, start, mid, left, right);
    long long r = mul(tree, node * 2 + 1, mid + 1, end, left, right);
    return l * r % FIELD;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K;
    int a, b, c;
    cin >> N >> M >> K;
    vector<int> input(N);
    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<int> tree(tree_size);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    init(input, tree, 1, 0, N - 1);
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            input[b] = c;
            update(tree, 1, 0, N - 1, b, c);
        } else if (a == 2) {
            b--; c--;
            cout << mul(tree, 1, 0, N - 1, b, c) << '\n';
        } else {
            assert(false);
        }
    }
}