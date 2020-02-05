#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
    int al = a.length(), bl = b.length();
    if (al < bl) { return true; }
    if (al > bl) { return false; }
    if (b.compare(a) > 0) { return true; }
    else { return false; }
}

int main(void) {
    int N; cin >> N; string input[N];
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    sort(input, input + N, comp);
    string s;
    for (int i = 0; i < N; i++) {
        if (s.compare(input[i])) { cout << input[i] << '\n'; s = input[i]; }
    }
}