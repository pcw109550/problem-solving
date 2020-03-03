#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, temp; cin >> N; stack<int> S;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp != 0) { S.push(temp); }
        else { S.pop(); }
    }
    long long sum = 0;
    while (!S.empty()) {
        sum += S.top(); S.pop();
    }
    cout << sum;
}