#include <bits/stdc++.h>
using namespace std;
bool isused1[15], isused2[29], isused3[29];
int result, n;

void backtrack(int k) {
    if (k == n) { result++; return; }
    int x = k;
    for (int y = 0; y < n; y++) {
        if (!isused1[y] && !isused2[x + y] && !isused3[x - y + n - 1]){
            isused1[y] = isused2[x + y] = isused3[x - y + n - 1] = true;
            backtrack(k + 1);
            isused1[y] = isused2[x + y] = isused3[x - y + n - 1] = false;   
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; n = N;
    backtrack(0); cout << result;
}