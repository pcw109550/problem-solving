#include <bits/stdc++.h>
using namespace std;

inline int decide() {
    string s; getline(cin, s);
    if (!s.compare("black"))       { return 0; }
    else if (!s.compare("brown"))  { return 1; }
    else if (!s.compare("red"))    { return 2; }
    else if (!s.compare("orange")) { return 3; }
    else if (!s.compare("yellow")) { return 4; }
    else if (!s.compare("green"))  { return 5; }
    else if (!s.compare("blue"))   { return 6; }
    else if (!s.compare("violet")) { return 7; }
    else if (!s.compare("grey"))   { return 8; }
    else if (!s.compare("white"))  { return 9; }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long result = (long long)(decide() * 10 + decide()) * ((int)pow(10, decide()));
    cout << result;
}