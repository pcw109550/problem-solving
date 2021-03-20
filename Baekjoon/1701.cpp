#include <bits/stdc++.h>
using namespace std;

int failure(string &S) {
    int N = S.size();
    int Max = 0;
    for (int b = 0; b < N; b++) {
        int j = 0;
        vector<int> f(N, 0);
        for (int i = 1; i < N - b; i++) {
            while (j > 0 && S[i + b] != S[j + b])
                j = f[j - 1];
            if (S[i + b] == S[j + b])
                f[i] = ++j;
            Max = max(Max, f[i]);
        }
    }
    return Max;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string S;
    cin >> S;
    cout << failure(S);
}