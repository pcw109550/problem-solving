#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string &S) {
    int N = S.size(), j = 0;
    vector<int> f(N, 0);
    for (int i = 1; i < N; i++) {
        while (j > 0 && S[i] != S[j])
            j = f[j - 1];
        if (S[i] == S[j])
            f[i] = ++j;
    }
    return f;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // KMP
    string T, P;
    getline(cin, T);
    getline(cin, P);
    int j = 0;
    auto f = failure(P);
    vector<int> occ;
    for (int i = 0; i < T.size(); i++) {
        while (j > 0 && T[i] != P[j])
            j = f[j - 1];
        if (T[i] == P[j])
            j++;
        if (j == P.size()) {
            occ.push_back(i + 2 - P.size());
            j = f[j - 1];
        }
    }
    cout << occ.size() << '\n';
    for (auto it : occ)
        cout << it << ' ';
} 