#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, div = 0; cin >> N;
    for (int i = 2; i <= (int)sqrt(N); i++) {
        if (N % i == 0) {
            div = i;
            break;
        }
    }
    if (div) {
        cout << N - N / div; 
    } else  {
        cout << N - 1;
    }
}