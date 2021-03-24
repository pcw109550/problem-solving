#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // (N - 2 * M + 1) * log(2 * M - 1) 
    int N, M; cin >> N >> M;
    multiset<int> S;
    vector<int> input(N);
    for (int i = 0; i < N; i++)
        cin >> input[i];
    for (int i = 0; i <= 2 * (M - 1) && i < N; i++)
        S.insert(input[i]);
    cout << *S.rbegin() << ' ';
    for (int i = M; i <= N - M; i++) {
        S.insert(input[i + M - 1]);
        S.erase(S.lower_bound(input[i - M]));
        cout << *S.rbegin() << ' ';
    }
}