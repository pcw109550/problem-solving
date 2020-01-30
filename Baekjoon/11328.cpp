#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin, s); int N = stoi(s);
    for (int i = 0; i < N; i++) {
        string a, b; cin >> a >> b; if (a.size() != b.size()) { cout << "Impossible\n"; continue; }
        list<char> a1 (a.begin(), a.end()); a1.sort();
        list<char> b1 (b.begin(), b.end()); b1.sort();
        if (!equal(a1.begin(), a1.end(), b1.begin())) { cout << "Impossible\n"; continue; }
        cout << "Possible\n";
    }
}