#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, temp, result = 0; cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 5 == 0) {
            temp = i;
            while (temp % 5 == 0) { result++; temp /= 5; } 
        }
    }
    cout << result;
}