#include <bits/stdc++.h>
using namespace std;

int failure(string &S) {
    int N = S.size(), j = 0;
    vector<int> f(N, 0);
    for (int i = 1; i < N; i++) {
        while (j > 0 && S[i] != S[j])
            j = f[j - 1];
        if (S[i] == S[j])
            f[i] = ++j;
    }
    return f[N - 1];
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int L;
    string S;
    cin >> L >> S;
    int f = failure(S);
    cout << L - f;
}