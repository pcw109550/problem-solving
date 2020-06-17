#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N; vector<bool> status(N, false);
    char temp; bool start = false; int result = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp; status[i] = temp == 'G';
    }
    for (int i = 0; i < N; i++) {
        cin >> temp; status[i] = status[i] ^ (temp == 'G');
        if (!start && status[i])      { start = true; result++; }
        else if (start && !status[i]) { start = false; }
    }
    cout << result;
}