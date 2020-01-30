#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    int N = stoi(s);
    int queue[10000];
    int start = 0, end = 0;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        //cout << start << " " << end << '\n';
        if (!s.compare(0, 4, "push")) {
            queue[end++] = atoi(s.c_str() + 5);
        } else if (!s.compare(0, 3, "pop")) {
            if (start == end) cout << "-1\n";
            else cout << queue[start++] << '\n';
        } else if (!s.compare(0, 4, "size")) {
            cout << (end - start) << '\n';
        } else if (!s.compare(0, 5, "empty")) {
            if (start == end) cout << "1\n";
            else cout << "0\n";
        } else if (!s.compare(0, 5, "front")) {
            if (start == end) cout << "-1\n";
            else cout << queue[start] << '\n';            
        } else if (!s.compare(0, 4, "back")) {
            if (start == end) cout << "-1\n";
            else cout << queue[end - 1] << '\n';
        }
    }
}