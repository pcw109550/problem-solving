#include <bits/stdc++.h>
using namespace std;

inline bool isPrime(int n) {
    if (n == 1) { return false; }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { return false; }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int M, N; cin >> M >> N;
    int cnt = 0;
    vector<int> Palindrome;
    for (int i = 1; i < 10000; i++) {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        Palindrome.push_back(stoi(to_string(i) + &s[1]));
        Palindrome.push_back(stoi(to_string(i) + s));
    }
    sort(Palindrome.begin(), Palindrome.end());
    for (auto it = Palindrome.begin(); it != Palindrome.end(); it++) {
        if (M <= *it && *it <= N && isPrime(*it)) { cout << *it << '\n'; }
    }
    cout << -1;
}