#include <bits/stdc++.h>
using namespace std;

inline void task() {
    int N, M, temp; cin >> N >> M;
    vector<int> A, B;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.emplace_back(temp);
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        B.emplace_back(temp);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int result = 0;
    for (auto a : A)
        result += lower_bound(B.begin(), B.end(), a) - B.begin();
    cout << result << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    int T; cin >> T;
    while (T--)
        task();
}