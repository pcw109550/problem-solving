#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string buffer;
    int output = 1;
    short array[10] = {};
    for(int i = 0; i < 3; i++) {
        getline(cin, buffer);
        output *= stoi(buffer);
    }
    string s = to_string(output);
    for (char const &c: s) {
        array[c - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        cout << array[i];
        if (i != 9)
            cout << '\n';
    }
}