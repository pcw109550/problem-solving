#include <bits/stdc++.h>
using namespace std;
#define FIELD 1000000007

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    long long input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    sort(input, input + N);
    long long result = 0;
    long long weight = 1;
    for (int i = 0; i < N; i++) {
        long long temp = weight * (input[i] - input[N - i - 1]);
        result = (result + temp) % FIELD;
        weight = (weight << 1) % FIELD;
    }
    cout << result;
}