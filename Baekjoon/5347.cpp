#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    long long a, b;
    cin >> N;
    while (N--) {
        cin >> a >> b;
        cout << a * b / __gcd(a, b) << '\n';
    }
}