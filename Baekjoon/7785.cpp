#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); int N;
    set<string, greater<string>> S; priority_queue<string> PQ; string name, status;
    cin >> N;
    for (int i = 0; i < N; i++) { // O(N * log(N))
        cin >> name >> status;
        if (!status.compare("enter")) { S.insert(name); }
        else { auto it = S.find(name); S.erase(it); }
    }
    for (auto it = S.begin(); it != S.end(); it++) {
        cout << *it << '\n'; // set is already sorted :D
    }
}