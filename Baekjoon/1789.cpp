#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N;
    cin >> N;
    int n = (-1 + static_cast<int>(sqrt(1 + 8 * N))) / 2;
    cout << n;
}   