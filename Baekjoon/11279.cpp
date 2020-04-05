#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    priority_queue<int> PQ;
    int N, temp; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == 0) {
            if (PQ.empty()) { cout << "0\n"; }
            else { cout << PQ.top() << '\n'; PQ.pop(); }
        } else { PQ.push(temp); }
    }
}