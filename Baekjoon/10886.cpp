#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int cnt = 0, temp;
    for (int i = 0; i < N; i++) {
        cin >> temp; if (temp) { cnt++; }
    }
    cout << "Junhee is ";
    if (cnt <= N / 2) { cout << "not "; }
    cout << "cute!";
}