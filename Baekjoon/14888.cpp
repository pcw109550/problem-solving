#include <bits/stdc++.h>
using namespace std;
#define BIGNUM 1000000001
int opnum[4]; int input[11];
int MIN = BIGNUM; int MAX = -BIGNUM;
int arr[10]; int n;
int cnt;

void backtrack(int k) {
    if (k == n - 1) {
        int result = input[0];
        for (int i = 0; i < k; i++) {
            if (arr[i] == 0) { result += input[i + 1]; }
            if (arr[i] == 1) { result -= input[i + 1]; }
            if (arr[i] == 2) { result *= input[i + 1]; }
            if (arr[i] == 3) { result /= input[i + 1]; }
            
        }
        if (result < MIN) { MIN = result; }
        if (result > MAX) { MAX = result; }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (opnum[i] > 0) {
            opnum[i]--; arr[k] = i; backtrack(k + 1); opnum[i]++;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; n = N; for (int i = 0; i < N; i++) { cin >> input[i]; }   
    for (int i = 0; i < 4; i++) { cin >> opnum[i]; }
    backtrack(0);
    cout << MAX << '\n' << MIN;
}