#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[15]; bool visited[15];

void backtrack(int k, char input[]) {
    if (k == n) {
        int vowel = 0;
        for (int i = 0; i < n; i++) {
            if (input[arr[i]] == 'a' || input[arr[i]] == 'e' || input[arr[i]] == 'i' || input[arr[i]] == 'o' || input[arr[i]] == 'u') {
                vowel++;       
            }
        }
        if (vowel >= 1 && (n - vowel) >= 2) { for (int i = 0; i < n; i++) { cout << input[arr[i]]; } cout << "\n"; }
        return;
    }
    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            if (k == 0 || arr[k - 1] < i) { arr[k] = i; visited[i] = true; backtrack(k + 1, input); visited[i] = false; }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int L, C; cin >> L >> C; char input[C] = {}; for (int i = 0; i < C; i++) { cin >> input[i]; }
    sort(input, input + C); n = L; m = C;
    backtrack(0, input);
}