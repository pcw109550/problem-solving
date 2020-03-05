#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int A, B, V; cin >> A >> B >> V;
    int amount = A - B;
    cout << ((V - A) / amount) + ((V - A) % amount != 0) + 1;
}