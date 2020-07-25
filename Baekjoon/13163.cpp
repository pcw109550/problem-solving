#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    string s;
    getline(cin, s);
    while (N--) {
        bool god = false;
        getline(cin, s);
        cout << "god";
        for (auto it : s) {
            if (!god && it == ' ') {
                god = true;
            } else if (god && it != ' ')
                cout << it;
        }
        cout << '\n';
    }
}