#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; int input[N];
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int p1 = 0, p2 = 0, result = 0, sum = 0;
    while (p1 < N) { // O(n)
        if (sum < M) { sum += input[p2++]; }
        else { 
            if (sum == M) { result++; }
            sum -= input[p1++];
        }
    }
    cout << result;
}