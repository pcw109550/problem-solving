#include <bits/stdc++.h>
using namespace std;

int N;
long long D[1000001];

void update(int idx, int val) {
    // O(log(N))
    while (idx <= N) {
        D[idx] += val;
        idx += idx & -idx;
    }
}

long long sum(int idx) {
    // O(log(N))
    long long result = 0;
    while (idx) {
        result += D[idx];
        idx -= idx & -idx;
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // BIT
    int Q, op, a, b;
    cin >> N >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> op >> a >> b;
        if (op == 1) {
            update(a, b);
        } else {
            cout << (sum(b) - sum(a - 1)) << '\n';
        }
    }
    return 0;
}   