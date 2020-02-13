#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n; int target[n];
    for (int i = 0; i < n; i++) { cin >> target[i]; }
    int k = *max_element(target, target + n);
    int D[k + 1] = {};
    D[1] = 1; D[2] = 2; D[3] = 4;
    for (int i = 4; i <= k; i++) {
        D[i] = D[i - 1] + D[i - 2] + D[i - 3]; 
    }
    for (int i = 0; i < n; i++) {
        cout << D[target[i]] << '\n';
    }
}