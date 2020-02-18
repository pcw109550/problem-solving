#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int A, B, C, result; cin >> A >> B >> C;
    if (C <= B) { result = -1; }
    else {
        result = A / (C - B) + 1;
    }
    cout << result;
}