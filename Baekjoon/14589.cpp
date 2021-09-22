#include <bits/stdc++.h>
using namespace std;
const int MN = 150001;
const int MAX = 1000000;
int R[2 * MAX + 1][18], num[MN];
struct line {
    int l, r, p;
} A[MN];

bool cmp(line A, line B) {
    return A.l < B.l;
}

int main() {
    // O((N + Q) * log(N))
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i].l >> A[i].r;
        A[i].l += MAX;
        A[i].r += MAX;
        A[i].p = i;
    }
    // O(N * log(N))
    sort(A + 1, A + N + 1, cmp);
    // O(N) position mapping
    for (int i = 1; i <= N; i++)
        num[A[i].p] = i;
    int pos = 1, cur = 0;
    for (int i = 0; i <= 2 * MAX; i++){
        while (pos <= N && A[pos].l <= i){
            cur = max(cur, A[pos].r);
            pos++;
        }
        R[i][0] = cur;
    }
    // O(N * log(N))
    for (int k = 1; k < 18; k++)
        for (int i = 0; i <= 2 * MAX; i++)
            R[i][k] = R[R[i][k - 1]][k - 1];
    // O(Q * log(N))
    cin >> Q;
    int u, v, result, uidx, vidx;
    for (int i = 0; i < Q; i++) {
        result = 1;
        cin >> uidx >> vidx;
        u = num[uidx];
        v = num[vidx];
        if (A[u].r > A[v].r)
            swap(u, v);
        if (A[u].r >= A[v].l){
            cout << 1 << '\n';
            continue;
        }
        int r = A[u].r;
        for (int k = 17; k >= 0; k--){
            int next_r = R[r][k];
            if (next_r >= A[v].l)
                continue;
            r = next_r;
            result += 1 << k;
        }
        if (R[r][0] >= A[v].l)
            result++;
        else
            result = -1;
        cout << result << '\n';
    }
}
