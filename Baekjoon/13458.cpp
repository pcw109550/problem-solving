#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; int A[N] = {}, B, C;
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    cin >> B >> C;
    long long result = N;
    for (int i = 0; i < N; i++) {
        if (A[i] > B) {
            result += (A[i] - B) / C + ((A[i] - B) % C != 0);
        }
    }
    cout << result;
}