#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    unordered_set<int> A, B; int N, M, cnt = 0, temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.insert(temp);
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (A.count(temp))
            cnt++;
        B.insert(temp);
    }
    cout << A.size() + B.size() - 2 * cnt;
}