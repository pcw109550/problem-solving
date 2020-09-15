#include<bits/stdc++.h>
using namespace std;

inline void task(int N) {
    string s;
    getline(cin, s);
    string s2;
    for (auto c : s) {
        if (c == ' ')
            continue;
        if ('a' <= c && c <= 'z')
            c = c - 'a' + 'A';
        s2.push_back(c);
    }
    int len = s2.size(), idx = 0, base = 0;
    string result(len, ' ');
    for (int i = 0; i < len; i++) {
        result[idx] = s2[i];
        idx += N;
        if (idx >= len) {
            base++;
            idx = base;
        }
    }
    cout << result << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    while (true) {
        cin >> N;
        cin.ignore();
        if (N == 0)
            return 0;
        task(N);
    }
}   