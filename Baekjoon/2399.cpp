#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long N; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    sort(input, input + N); long long result = 0;
    for (long long i = 1; i < N; i++) {
        result += (input[i] - input[i - 1]) * (N - i) * i; 
    }
    cout << (result << 1);
}