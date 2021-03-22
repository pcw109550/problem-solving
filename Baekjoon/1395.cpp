#include <bits/stdc++.h>
using namespace std;

void update_lazy(vector<pair<int, int> > &tree, int node, int start, int end) {
    if (tree[node].second == 0)
        return;
    tree[node].first = (end - start + 1 - tree[node].first) * tree[node].second;
    if (start != end) {
        tree[node * 2].second ^= tree[node].second;
        tree[node * 2 + 1].second ^= tree[node].second;
    }
    tree[node].second = 0;
}

void update(vector<pair<int, int> > &tree, int node, int start, int end, int left, int right) {
    // O(log (N))
    update_lazy(tree, node, start, end);
    if (right < start || left > end)
        return;
    if (left <= start && end <= right) {
        tree[node].first = end - start + 1 - tree[node].first; 
        if (start != end) {
            tree[node * 2].second ^= 1;
            tree[node * 2 + 1].second ^= 1;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(tree, node * 2, start, mid, left, right);
    update(tree, node * 2 + 1, mid + 1, end, left, right);
    tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
}

long long sum(vector<pair<int, int> > &tree, int node, int start, int end, int left, int right) {
    // O(log (N))
    // Exhaust current node's lazy
    update_lazy(tree, node, start, end);
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node].first;
    int mid = (start + end) / 2;
    long long result = sum(tree, node * 2, start, mid, left, right);
    result += sum(tree, node * 2 + 1, mid + 1, end, left, right);
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K;
    long long a, b, c, d;
    cin >> N >> M;
    vector<long long> input(N, 0);
    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<pair<int, int> > tree(tree_size); // {value, lazy}
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        b--; c--;
        if (a == 0) {
            update(tree, 1, 0, N - 1, b, c);
        } else {
            long long result = sum(tree, 1, 0, N - 1, b, c);
            cout << result << '\n';
        }
    }
}