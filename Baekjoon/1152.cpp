#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); string s; getline(cin, s);
    int result = 0; bool in = false; char *input = (char *)s.c_str();
    for (int i = 0; i < s.length(); i++) {
        if (input[i] != ' ' && !in) { result++; in = true; }
        else if (input[i] == ' ') { in = false; }
    }
    cout << result;
}