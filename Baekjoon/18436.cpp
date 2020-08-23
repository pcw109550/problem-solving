#include <bits/stdc++.h>
using namespace std;

pair<int, int> init(vector<int> &input, vector<pair<int, int> > &tree, int node, int start, int end) {
    // O(N)
    if (start == end) {
        int parity = input[start] & 1;
        tree[node] = {parity, 1 - parity};
    } else {
        int mid = (start + end) / 2;
        auto l = init(input, tree, node * 2, start, mid);
        auto r = init(input, tree, node * 2 + 1, mid + 1, end);
        tree[node] = {l.first + r.first, l.second + r.second};
    }
    return tree[node];
}

void update(vector<pair<int, int> > &tree, int node, int start, int end, int idx, int diff) {
    // O(log (N))
    if (idx < start || idx > end)
        return;
    if (diff == 1) {
        tree[node].first++;
        tree[node].second--;
    } else {
        tree[node].first--;
        tree[node].second++;
    }
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, idx, diff);
        update(tree, node * 2 + 1, mid + 1, end, idx, diff);
    }
}

pair<int, int> query(vector<pair<int, int> > &tree, int node, int start, int end, int left, int right) {
    // O(log (N))
    if (left > end || right < start)
        return {0, 0};
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    auto l = query(tree, node * 2, start, mid, left, right);
    auto r = query(tree, node * 2 + 1, mid + 1, end, left, right);
    pair<int, int> result = {l.first + r.first, l.second + r.second};
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
    vector<pair<int, int> > tree(tree_size); // {odd, even}
    for (int i = 0; i < N; i++)
        cin >> input[i];
    init(input, tree, 1, 0, N - 1);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            if ((input[b] & 1) == (c & 1)) {
                input[b] = c;
                continue;
            }
            int diff = c & 1;
            input[b] = c;
            update(tree, 1, 0, N - 1, b, diff);
        } else if (a == 2 || a == 3) {
            auto result = query(tree, 1, 0, N - 1, b - 1, c - 1);
            cout << (a == 2 ? result.second : result.first) << '\n';
        }
    }
}