#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N, P;
    cin >> N >> P;
    long long result = 1;
    for (int i = 1; i <= N; i++) {
        result = (result * i) % P;
    }
    cout << result;
}   