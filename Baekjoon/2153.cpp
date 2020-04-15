#include <bits/stdc++.h>
using namespace std;

inline bool isPrime(int n) {
    if (n == 1) { return true; } // Just for this problem
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { return false; }
    }
    return true;
}

inline int gen(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') { sum += s[i] - 'A' + 27; }
        if ('a' <= s[i] && s[i] <= 'z') { sum += s[i] - 'a' + 1; }
    }
    return sum;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    cout << "It is" << (isPrime(gen(s)) ? "" : " not") << " a prime word.";
}