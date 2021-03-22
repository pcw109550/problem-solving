#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int> t;
void build() {
    // O(N)
    for (int i = n - 1; i >= 1; --i)
        t[i] = min(t[i << 1], t[(i << 1) | 1]);
}

void modify(int idx, int value) {
    // O(log(N))
    idx += n - 1;
    t[idx] = value;
    while (idx >>= 1)
        t[idx] = min(t[idx << 1], t[(idx << 1) | 1]);
}

int get_min(int l, int r) {
    // O(log(N))
    int ans = INT_MAX;
    l += n - 1, r += n - 1;
    while (l <= r) {
        if (l & 1)
            ans = min(ans, t[l++]);
        if (!(r & 1))
            ans = min(ans, t[r--]);
        l >>= 1; r >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> l;
    int h = static_cast<int>(ceil(log2(n)));
    int tree_size = 1 << (h + 1);
    t.resize(tree_size, 0);
    for (int i = 1; i <= n; i++)
        cin >> t[i + n - 1];
    build();
    for (int i = 1; i <= n; i++)
        cout << get_min((i - l + 1 <= 0 ? 1 : i - l + 1), i) << ' ';
}