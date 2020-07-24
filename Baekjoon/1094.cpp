#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, result = 0;
    cin >> N;
    while (N > 0) {
        if (N & 1)
            result++;
        N >>= 1;
    }
    cout << result;
}