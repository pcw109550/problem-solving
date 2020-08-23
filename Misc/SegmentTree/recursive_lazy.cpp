#include <bits/stdc++.h>
using namespace std;

long long init(vector<long long> &input, vector<pair<long long, long long> > &tree, int node, int start, int end) {
    // O(N)
    if (start == end)
        tree[node].first = input[start];
    else {
        int mid = (start + end) / 2;
        tree[node].first = init(input, tree, node * 2, start, mid);
        tree[node].first += init(input, tree, node * 2 + 1, mid + 1, end);
    }
    return tree[node].first;
}

void update_lazy(vector<pair<long long, long long> > &tree, int node, int start, int end) {
    // Exhaust current node's lazy
    if (tree[node].second == 0)
        return;
    tree[node].first += (end - start + 1) * tree[node].second;
    if (start != end) {
        tree[node * 2].second += tree[node].second;
        tree[node * 2 + 1].second += tree[node].second;
    }
    tree[node].second = 0;
}

void update(vector<pair<long long, long long> > &tree, int node, int start, int end, int left, int right, long long diff) {
    // O(log (N))
    update_lazy(tree, node, start, end);
    if (right < start || left > end)
        return;
    if (left <= start && end <= right) {
        tree[node].first += (end - start + 1) * diff;
        if (start != end) {
            tree[node * 2].second += diff;
            tree[node * 2 + 1].second += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(tree, node * 2, start, mid, left, right, diff);
    update(tree, node * 2 + 1, mid + 1, end, left, right, diff);
    tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
}

long long sum(vector<pair<long long, long long> > &tree, int node, int start, int end, int left, int right) {
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
    cin >> N >> M >> K;
    vector<long long> input(N);
    int h = static_cast<int>(ceil(log2(N)));
    int tree_size = 1 << (h + 1);
    vector<pair<long long, long long> > tree(tree_size); // {value, lazy}
    for (int i = 0; i < N; i++)
        cin >> input[i];
    init(input, tree, 1, 0, N - 1);
    for (int i = 0; i < M + K; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            b--; c--;
            update(tree, 1, 0, N - 1, b, c, d);
        } else {
            cin >> b >> c;
            b--; c--;
            long long result = sum(tree, 1, 0, N - 1, b, c);
            cout << result << '\n';
        }
    }
}