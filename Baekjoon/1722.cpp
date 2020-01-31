#include <bits/stdc++.h>
using namespace std;
long long factorial(int n){
    long long result = 1;
    for (long long i = 1; i <= n; i++) { result *= i; }
    return result;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, temp; cin >> N >> temp; long long value = factorial(N);
    if (temp == 1) {
        long long k, idx; cin >> k; k-= 1;
        list<int> L; for (int i = 1; i <= N; i++) { L.push_back(i); }
        for (int i = N; i >= 1; i--) {
            value /= i; idx = k / value; k %= value; auto it = L.begin(); advance(it, idx); cout << *it; L.erase(it);
            if (i != 1) { cout << " "; }
        }
    } else {
        int input[N] = {}; for (int i = 0; i < N; i++) { cin >> input[i]; }
        list<int> L; for (int i = 1; i <= N; i++) { L.push_back(i); }
        long long result = 0, idx = 0;
        for (int i = N; i >= 1; i--) {
            for (auto it = L.begin(); it != L.end(); it++) { if (*it == input[N - i]) { L.erase(it); break; } idx++; }
            value /= i; result += value * idx; idx = 0;
        }
        cout << result + 1;
    }
}