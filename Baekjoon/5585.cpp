#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; N = 1000 - N;
    int result = 0; int A[6] = {500, 100, 50, 10, 5, 1};
    int cnt = 0;
    while (N != 0) {
        if (N >= A[cnt]) {
            result += N / A[cnt];
            N %= A[cnt]; 
        }
        cnt++;
    }
    cout << result;
}