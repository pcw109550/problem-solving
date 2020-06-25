#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int X, Y; cin >> X >> Y;
    cout << (1 + X / (Y - X) + (X % (Y - X) != 0));   
}