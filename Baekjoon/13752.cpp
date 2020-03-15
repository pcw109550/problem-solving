#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, temp; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = 0; j < temp; j++) { cout << '='; } cout << '\n';
    }
}