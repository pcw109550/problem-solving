#include<bits/stdc++.h>
using namespace std;

int n;
vector<long long> t;
void build() {
    // O(N)
    for (int i = n - 1; i >= 1; --i)
        t[i] = t[i << 1] + t[(i << 1) | 1];
}

void modify(int idx, int value) {
    // O(log(N))
    idx += n - 1;
    t[idx] = value;
    while (idx >>= 1)
        t[idx] = t[idx << 1] + t[(idx << 1) | 1];
}

long long sum(int l, int r) {
    // O(log(N))
    long long ans = 0;
    l += n - 1, r += n - 1;
    while (l <= r) {
        if (l & 1)
            ans += t[l++];
        if (!(r & 1))
            ans += t[r--];
        l >>= 1; r >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int m, k, a, b, c;
    cin >> n >> m >> k;
    int h = static_cast<int>(ceil(log2(n)));
    int tree_size = 1 << (h + 1);
    t.resize(tree_size, 0);
    for (int i = 1; i <= n; i++)
        cin >> t[i + n - 1];
    build();
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1)
            modify(b, c);
        else
            cout << sum(b, c) << '\n';
    }
}
