#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string s;
    getline(cin, s);
    N = stoi(s);
    int stack[10000] = {};
    int top = 0;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        if(!s.compare(0, 4, "push")) {
            stack[top++] = atoi(s.c_str() + 5);
        } else if (!s.compare(0, 3, "pop")) {
            if (top != 0) cout << stack[(top--)-1] << '\n';
            else cout << -1 << '\n';
        } else if (!s.compare(0, 4, "size")) {
            cout << top << '\n';
        } else if (!s.compare(0, 5, "empty")) {
            cout << (top == 0) << '\n';
        } else if (!s.compare(0, 3, "top")) {
            if (top != 0) cout << stack[top - 1] << '\n';
            else cout << "-1\n";
        }
    }   
}