#include <bits/stdc++.h>
using namespace std;

int xcnt, ycnt;
bool result;
string s, state;

bool end(string &s) {
    if (s[0] != '.' && s[0] == s[3] && s[3] == s[6])
        return true;
    if (s[1] != '.' && s[1] == s[4] && s[4] == s[7])
        return true;
    if (s[2] != '.' && s[2] == s[5] && s[5] == s[8])
        return true;
    if (s[0] != '.' && s[0] == s[1] && s[1] == s[2])
        return true;
    if (s[3] != '.' && s[3] == s[4] && s[4] == s[5])
        return true;
    if (s[6] != '.' && s[6] == s[7] && s[7] == s[8])
        return true;
    if (s[0] != '.' && s[0] == s[4] && s[4] == s[8])
        return true;
    if (s[2] != '.' && s[2] == s[4] && s[4] == s[6])
        return true;
    for (auto it : s)
        if (it == '.')
            return false;
    return true;
}

void print_state(string &state) {
    cout << "---\n";
    for (int i = 0; i < 3; i++)
        cout << state.substr(3 * i, 3) << '\n';
}

void backtrack(int _xcnt, int _ycnt, bool turn) {
    if (result)
        return;
    if (end(state)) {
        if (xcnt == _xcnt && ycnt == _ycnt && s == state)
            result = true;
        return;
    }
    char add = turn ? 'O' : 'X';
    for (int i = 0; i < 9; i++) {
        if (state[i] == '.' && s[i] == add) {
            state[i] = add;
            backtrack(_xcnt + !turn, _ycnt + turn, !turn);
            state[i] = '.';
        }
    }
}

bool verify(string &s) {
    state = string (9, '.');
    result = false;
    xcnt = 0; ycnt = 0;
    for (auto it : s) {
        if (it == 'X')
            xcnt++;
        else if (it == 'O')
            ycnt++;
    }
    if (xcnt < 3)
        return false;
    if (!(xcnt == ycnt || xcnt == ycnt + 1))
        return false;
    backtrack(0, 0, false);
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while (true) {
        getline(cin, s);
        if (s == "end")
            return 0;
        cout << (verify(s) ? "valid\n" : "invalid\n");
    }
    return 0;
}