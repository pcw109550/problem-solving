#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    int temp;
    if (N == 1) {
        cout << 1;
        return 0;
    }
    long long prev = 1, current;
    for (int i = 2; i <= N; i++) {
        temp = i;
        current = prev;
        while (temp % 5 == 0) {
            temp /= 5;
            current /= 2;
        }
        current *= temp;
        current %= 1000000;
        prev = current;
    }
    cout << current % 10;
}   