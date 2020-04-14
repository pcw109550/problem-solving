#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M; string input[N] = {};
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> temp;
        auto it2 = temp.begin();
        for (auto it = input[i].begin(); it != input[i].end(); it++) {
            if (*it2++ != *it) { cout << "Not Eyfa"; return 0; }
            if (*it2++ != *it) { cout << "Not Eyfa"; return 0; }
        }
    }
    cout << "Eyfa";
}