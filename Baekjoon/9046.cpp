#include<bits/stdc++.h>
using namespace std;

inline void task(void) {
    string s; getline(cin, s);
    unordered_map<char, int> M;
    int Max = -1, idx = 0; char c; bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')
            continue;
        if (M.find(s[i]) == M.end())
            M[s[i]] = 1;
        else
            M[s[i]]++;;
        if (Max < M[s[i]]) {
            c = s[i];
            Max = M[s[i]];
            flag = false;
        } else if (Max == M[s[i]]) {
            flag = true;
        }
    }
    cout << (flag ? '?' : c) << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    cin.ignore();
    while (N--)
        task();
}   